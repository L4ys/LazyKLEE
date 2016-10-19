#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
from commands import getoutput

GREEN = "\033[92m"
RED = "\033[91m"
GRAY = "\033[90m"
ENDC = "\033[0m"

def docker_exec(cmd):
    return getoutput("docker exec lazyklee " + cmd)

def main():
    if len(sys.argv) != 2:
        print "Usage: %s <source code>" % sys.argv[0]
        exit()

    print "=== LazyKLEE ==="

    src = sys.argv[1]
    if not os.path.isfile(src):
        print "Souce code [%s] not found!" % src
        exit()

    if not getoutput("which docker"):
        print "docker not found, install docker first"
        exit()

    if not getoutput("docker images | grep klee"):
        print "KLEE image not found, run docker pull klee/klee first"
        exit()

    path = os.path.dirname(src)
    file_name = src.split("/")[-1]

    print "[+] Creating container..."
    getoutput("docker rm -f lazyklee")
    print GRAY + getoutput("docker run -d -t --name lazyklee -v %s:/home/klee/work/ klee/klee" % path) + ENDC

    print "\n[+] Compiling llvm bitcode..."
    out = docker_exec("clang -emit-llvm -c -g -I klee_src/include/ ./work/%s -o out.bc" % file_name) 
    if "error:" in out:
        print RED + out + ENDC
        exit()
    else:
        print GRAY + out + ENDC

    print "\n[+] Running KLEE..."
    klee_out = docker_exec("klee ./out.bc")
    if "ASSERTION FAIL" not in klee_out:
        print RED + "[!] ASSERTION not triggered..." + ENDC
        print klee_out
    else:
        print GREEN + "[+] ASSERTION triggered!" + ENDC
        test_case = docker_exec("ls ./klee-last/ | grep .assert.err").split(".")[0] + ".ktest"
        print docker_exec("ktest-tool ./klee-last/" + test_case)

    print "\n[+] Remove container..."
    getoutput("docker rm -f lazyklee")

if __name__ == "__main__":
    main()
