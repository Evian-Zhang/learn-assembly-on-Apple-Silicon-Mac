    .section    __TEXT,__text
    .globl  _main
    .p2align    2
_main:
    ldr    w1, =13
    ldr    w2, =5
    sdiv   w0, w1, w2
    mul    w0, w2, w0
    sub    w0, w1, w0
    ret
