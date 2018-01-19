```sh
$ LazyKLEE.py ./solve.c
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
