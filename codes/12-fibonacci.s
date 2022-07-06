    .section    __TEXT,__text
    .globl  _main
    .p2align    2
fibonacci:
    sub    sp, sp, #32
    stp    x29, x30, [sp, #16]
    add    x29, sp, #16
    str    w0, [x29, #-4]
    cmp    w0, #2
    b.lt   init_val
    sub    w0, w0, #1
    bl     fibonacci
    str    w0, [x29, #-8]
    ldr    w0, [x29, #-4]
    sub    w0, w0, #2
    bl     fibonacci
    ldr    w1, [x29, #-8]
    add    w0, w0, w1
    ldp    x29, x30, [sp, #16]
    add    sp, sp, #32
    ret
init_val:
    mov    w0, #1
    ldp    x29, x30, [sp, #16]
    add    sp, sp, #32
    ret


    .p2align    2
_main:
    sub    sp, sp, #16
    stp    x29, x30, [sp]
    mov    w0, #6
    bl     fibonacci
    ldp    x29, x30, [sp]
    add    sp, sp, #16
    ret
