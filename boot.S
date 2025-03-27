.section .vectors
vector_table:
    .word __stack
    .word reset_handler
    .word default
    .word default
    .word default
    .word default
    .word default
    .word default
    .word default
    .word default
    .word default
    .word vPortSVCHandler
    .word default
    .word default
    .word xPortPendSVHandler
    .word xPortSysTickHandler
    .word default
    .zero 400

    .section .text
    .align 1
    .type reset_handler, %function
reset_handler:
    mov r1, #0x1
    mov r2, #0x2
    add r3, r1, r2
    bl main
    b .

    .section .text
    .align 1
    .type default, %function
default:
    b .
