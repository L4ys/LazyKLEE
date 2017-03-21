#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
from commands import getoutput

GREEN = "\033[92m"
RED = "\033[91m"
GRAY = "\033[90m"
ENDC = "\033[0m"

def usage():
    print "Usage: %s [-o|-i|-l|-- args to klee] <source code>" % sys.argv[0]
    print "   -i: interact with container after running KLEE"
    print "   -o: Run KLEE with --optimize"
    print "   -l: Run KLEE with --libc=uclibc --posix-runtime"
    exit()

def docker_exec(cmd):
    return getoutput("docker exec lazyklee " + cmd)

def main():
    if len(sys.argv) < 2 or "-h" in sys.argv:
        usage()

    optimize = "-o" in sys.argv
    interact = "-i" in sys.argv
    uclibc = "-l" in sys.argv

    print "=== LazyKLEE ==="

    src = sys.argv[-1]
    if not os.path.isfile(src):
        print "Souce code [%s] not found!" % src
        exit()

    if not getoutput("which docker"):
        print "docker not found, install docker first"
        exit()

    if not getoutput("docker images | grep klee"):
        print "KLEE image not found, run docker pull klee/klee first"
        exit()

    path = os.path.dirname(os.path.abspath(src))
    file_name = src.split("/")[-1]

    print "[+] Creating container..."
    getoutput("docker rm -f lazyklee")
    getoutput("docker run -d -t --ulimit='stack=-1:-1' --name lazyklee -v %s:/home/klee/work/ klee/klee" % path)

    print "[+] Compiling llvm bitcode..."
    clang_include = ""
    with open(src, "r") as f:
        code = f.read()
    if "klee.h" not in code:
        clang_include += "-include klee/klee.h "
    if "assert.h" not in code:
        clang_include += "-include assert.h "

    out = docker_exec("clang -emit-llvm -c -g -I klee_src/include/ %s ./work/%s -o out.bc" % (clang_include, file_name))
    if "error:" in out:
        out = out.replace("error", RED + "error" + ENDC)
        print out
        if interact:
            print "\n[+] Entering container..."
            os.system("docker exec -i -t lazyklee /bin/bash")

        exit()
    else:
        print GRAY + out + ENDC

    print "[+] Running KLEE..."
    cmd = "klee ./out.bc "
    if optimize:
        cmd += "--optimize "
    if uclibc:
        cmd += "--libc=uclibc --posix-runtime "
    if "--" in sys.argv and sys.argv[-1] != "--":
        cmd += " ".join(sys.argv[sys.argv.index("--")+1:])
    print GRAY + cmd + ENDC
    out = docker_exec(cmd)
    if "ASSERTION FAIL" not in out:
        print RED + "[!] ASSERTION not triggered..." + ENDC
        print out
    else:
        print GREEN + "[+] ASSERTION triggered!" + ENDC
        test_case = docker_exec("ls ./klee-last/ | grep .assert.err").split(".")[0] + ".ktest"
        print docker_exec("ktest-tool ./klee-last/" + test_case)

    if interact:
        print "\n[+] Entering container..."
        os.system("docker exec -i -t lazyklee /bin/bash")

    print "[+] Removing container..."
    getoutput("docker rm -f lazyklee")

if __name__ == "__main__":
    main()
