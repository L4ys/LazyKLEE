# LazyKLEE
Lazy python wrapper of KLEE for solving CTF challenges.

## Installation
- Install Docker
- `docker pull klee/klee`

## Usage
```sh
usage: LazyKLEE.py [-h] [-v] [-i] [-o] [-l] [-p] [-w] [-c CLANG_ARGS]
                   [-k KLEE_ARGS] [-a ARGS]
                   src

positional arguments:
  src                   source code

optional arguments:
  -h, --help            show this help message and exit
  -v, --verbose         show verbose message
  -i, --interact        interact with container after running KLEE
  -o, --optimize        run KLEE with -optimize
  -l, --libc            run KLEE with -libc=uclibc
  -p, --posix           run KLEE with -posix-runtime
  -w, --write-ints      convert 4-byte sequences to integers in ktest-tool
  -c CLANG_ARGS, --clang-args CLANG_ARGS
                        additional arguments for clang
  -k KLEE_ARGS, --klee-args KLEE_ARGS
                        additional arguments for KLEE
  -a ARGS, --args ARGS  additional arguments for target program
```

## Example
```sh
$ LazyKLEE.py ~/ctf/defcon_2016_quals/amadhj/amadhj.c
=== LazyKLEE ===
[+] Creating container...
[+] Compiling llvm bitcode...
    Auto include klee/klee.h
    Auto include assert.h
    ...
[+] Running KLEE...
[!] ASSERTION triggered!
    ktest file : './klee-last/test000002.ktest'
    args       : ['amadhj.bc']
    num objects: 1
    object    0: name: b'input'
    object    0: size: 32
    object    0: data: b'J XFAMFZi f wh yr ASQWcPCe_DjpT '
[+] Removing container...
```

Ref: http://blog.l4ys.tw/2016/05/defcon-ctf-quals-2016-amadhj/
