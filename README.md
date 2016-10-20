# LazyKLEE
Lazy python wrapper of klee

## Installation
- Install Docker
- `docker pull klee/klee`

## Example
```sh
$ python LazyKLEE.py ~/CTF/defcon_2016_quals/amadhj/amadhj.c
=== LazyKLEE ===
[+] Creating container...
ef081e5c089fd47f0b5e8040ac001a0a6d99ec4983f4a02398e87d6cb841b61d

[+] Compiling llvm bitcode...


[+] Running KLEE...
[+] ASSERTION triggered!
ktest file : './klee-last/test000002.ktest'
args       : ['./out.bc']
num objects: 1
object    0: name: b'input'
object    0: size: 32
object    0: data: b'kj   kr  n ZC YV kykBn  Zdk Inxi'

[+] Remove container...
```

Ref: http://blog.l4ys.tw/2016/05/defcon-ctf-quals-2016-amadhj/
