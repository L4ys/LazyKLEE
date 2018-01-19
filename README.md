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
$ LazyKLEE.py ~/CTF/defcon_2017/crackme1/solve.c
=== LazyKLEE ===
[+] Creating container...
[+] Compiling llvm bitcode...
    Auto include klee/klee.h
    Auto include assert.h

[+] Running KLEE...
[!] ASSERTION triggered!
    ktest file : './klee-last/test000032.ktest'
    args       : ['solve.bc']
    num objects: 1
    object    0: name: b'input'
    object    0: size: 80
    object    0: data: b'yes and his hands shook with ex\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00'
[+] Removing container...
```
