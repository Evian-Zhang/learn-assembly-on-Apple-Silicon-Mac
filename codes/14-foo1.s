    .text
    .globl    bar1
    .p2align 2
bar1:
    sub    sp, sp, #16
    stp    x29, x30, [sp]

    adrp   x0, my_str@PAGE
    add    x0, x0, my_str@PAGEOFF
    bl     _printf

    ldp    x29, x30, [sp]
    add    sp, sp, #16
    ret

    .data
my_str:
    .asciz "This is bar1 in foo1\n"
