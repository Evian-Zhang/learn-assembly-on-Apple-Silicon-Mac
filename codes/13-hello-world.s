    .text
    .globl  _main
    .p2align    2
_main:
    sub    sp, sp, #16
    stp    x29, x30, [sp]

    mov    w0, #0                       ; fd: STDOUT_FILENO
    adrp   x1, my_str@PAGE
    add    x1, x1, my_str@PAGEOFF       ; cbuf: "Hello world"
    mov    w2, #12                      ; nbyte: 12
    mov    w16, #4                      ; Syscall number: write
    svc    #0x80                        ; write(STDOUT_FILENO, "Hello world", 12);

    ldp    x29, x30, [sp]
    add    sp, sp, #16
    ret

    .data
my_str:
    .asciz    "Hello world"
