```sh
$ LazyKLEE.py ./solve.c
=== LazyKLEE ===
[+] Creating container...
[+] Compiling llvm bitcode...
    Auto include klee/klee.h
    Auto include assert.h
[+] Running KLEE...
[!] ASSERTION triggered!
    ktest file : './klee-last/test000001.ktest'
    args       : ['solve.bc']
    num objects: 1
    object    0: name: b'input'
    object    0: size: 16
    object    0: data: b'Tur!n9-C0mpl3t3?'
[+] Removing container...
```
