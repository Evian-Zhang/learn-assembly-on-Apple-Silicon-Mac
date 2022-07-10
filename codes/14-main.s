    .text
    .globl  _main
    .p2align    2
_main:
    sub    sp, sp, #16
    stp    x29, x30, [sp]

    bl     bar1
    bl     bar2

    mov    w0, #0

    ldp    x29, x30, [sp]
    add    sp, sp, #16
    ret
