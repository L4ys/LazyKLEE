```sh
$ LazKLEE.py ./solve.c -o
=== LazyKLEE ===
[+] Creating container...
[+] Compiling llvm bitcode...
    Auto include klee/klee.h
    Auto include assert.h
    ...
    2 warnings generated.
[+] Running KLEE...
[!] ASSERTION triggered!
    ktest file : './klee-last/test000001.ktest'
    args       : ['solve.bc']
    num objects: 1
    object    0: name: b'input'
    object    0: size: 32
    object    0: data: b'mpM PmYZTHOIxjmdup dn Jq QHQqPXB'
[+] Removing container...
```
