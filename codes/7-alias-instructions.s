    .section    __TEXT,__text
    .globl  _main
    .p2align    2
_main:
    neg    w0, w1
    sub    w0, wzr, w1
    ret
