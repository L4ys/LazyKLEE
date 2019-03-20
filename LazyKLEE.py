#!/usr/bin/env python
# -*- coding: utf-8 -*-
import argparse
import atexit
import os
from commands import getoutput, getstatusoutput

GRAY = "\033[90m"
RED = "\033[91m"
GREEN = "\033[92m"
YELLOW = "\033[93m"
ENDC = "\033[0m"

def indent(text, width=4):
    return " " * width + text.replace("\n", "\n" + " " * width)

def docker_exec(cmd):
    if args.verbose:
        print indent(GRAY + "$ " + cmd + ENDC)
    return getstatusoutput("docker exec lazyklee %s" % cmd)

def run_container(path):
    print "[+] Creating container... (%s)" % args.image
    getoutput("docker rm -f lazyklee")
    ret, out = getstatusoutput("docker run -d -t --ulimit='stack=-1:-1' --name=lazyklee -v %s:/home/klee/work/:ro %s" % (path, args.image))
    if ret:
        print RED + "Failed" + ENDC
        print indent(out)
        exit()

def compile_bitcode(file_name, out_name):
    print "[+] Compiling llvm bitcode..."

    ret, clang_path = docker_exec("bash -c 'which clang || which /tmp/llvm-*install*/bin/clang'")
    if ret or not clang_path:
        print RED + "Cannot get clang binary path: %s" % clang_path

    cmd = "%s -emit-llvm -c -g -DKLEE -I klee_src/include/" % clang_path

    with open(args.src, "r") as f:
        code = f.read()
    if "klee.h" not in code:
        cmd += " -include klee/klee.h"
        print indent(GREEN + "Auto include klee/klee.h" + ENDC)
    if "assert.h" not in code:
        cmd += " -include assert.h"
        print indent(GREEN + "Auto include assert.h" + ENDC)
    if args.clang_args:
        cmd += " " + args.clang_args
    cmd += " work/%s -o %s" % (file_name, out_name)

    ret, out = docker_exec(cmd)
    out = out.replace("warning:", YELLOW + "warning" + GRAY + ":")
    out = out.replace("error:", RED + "error" + GRAY + ":")
    if out:
        print indent(GRAY + out + ENDC)
    if ret:
        exit()

def run_klee(out_name):
    print "[+] Running KLEE..."

    cmd = "/home/klee/klee_build/bin/klee"
    cmd += " -check-overshift=0"
    cmd += " -check-div-zero=0"
    cmd += " -exit-on-error"
    cmd += " -exit-on-error-type=Assert"

    if args.optimize:
        cmd += " -optimize"
    if args.libc:
        cmd += " -libc=uclibc"
    if args.posix:
        cmd += " -posix-runtime"
    if args.klee_args:
        cmd += " " + args.klee_args
    cmd += " " + out_name
    if args.args:
        cmd += " " + args.args

    ret, out = docker_exec(cmd)
    out = out.replace("WARNING:", YELLOW + "WARNING" + GRAY + ":")
    out = out.replace("WARNING ONCE:", YELLOW + "WARNING ONCE" + GRAY + ":")
    out = out.replace("ERROR:", RED + "ERROR" + GRAY + ":")
    out = GRAY + out + ENDC
    if "ASSERTION FAIL" in out:
        if args.verbose:
            print indent(out)
        print "[!] " + GREEN + "ASSERTION triggered!" + ENDC

        _, out = docker_exec("ls ./klee-last/ | grep .assert.err")
        test_case = out.split(".")[0] + ".ktest"
        cmd = "/home/klee/klee_build/bin/ktest-tool "
        if args.write_ints:
            cmd += "--write-ints "
        cmd += "./klee-last/%s" % test_case
        _, out = docker_exec(cmd)
        print indent(out)
    else:
        print indent(out)
        print "[!] " + RED + "ASSERTION not triggered..." + ENDC

def cleanup():
    if args.interact:
        print "\n[+] Entering container..."
        os.system("docker exec -it lazyklee /bin/bash")

    if getoutput("docker ps -a | grep lazyklee"):
        print "[+] Removing container..."
        getoutput("docker rm -f lazyklee")

def main():
    global args
    parser = argparse.ArgumentParser()
    parser.add_argument("src", help="source code")
    parser.add_argument("-v", "--verbose", help="show verbose message", action="store_true")
    parser.add_argument("-i", "--interact", help="interact with container after running KLEE", action="store_true")
    parser.add_argument("-g", "--image", help="KLEE docker image name", default="klee/klee")
    parser.add_argument("-o", "--optimize", help="run KLEE with -optimize", action="store_true")
    parser.add_argument("-l", "--libc", help="run KLEE with -libc=uclibc", action="store_true")
    parser.add_argument("-p", "--posix", help="run KLEE with -posix-runtime", action="store_true")
    parser.add_argument("-c", "--clang-args", help="additional arguments for clang")
    parser.add_argument("-k", "--klee-args", help="additional arguments for KLEE")
    parser.add_argument("-a", "--args", help="additional arguments for target program")
    args = parser.parse_args()

    print "=== LazyKLEE ==="

    if not os.path.isfile(args.src):
        print "Souce code [%s] not found!" % args.src
        exit()

    if not getoutput("which docker"):
        print "docker not found, install docker first"
        exit()

    if not getoutput("docker images | grep klee"):
        print "KLEE image not found, run `docker pull klee/klee` first"
        exit()

    path = os.path.dirname(os.path.abspath(args.src))
    file_name = os.path.basename(args.src)
    out_name = os.path.splitext(file_name)[0] + ".bc"

    atexit.register(cleanup)

    run_container(path)
    compile_bitcode(file_name, out_name)
    run_klee(out_name)

if __name__ == "__main__":
    main()

