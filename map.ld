MEMORY
{
    FLASH : ORIGIN = 0x0, LENGTH = 128K
    RAM : ORIGIN = 0x20000000, LENGTH = 8K
}

SECTIONS
{
    .text : {
        *(.vectors*)
        *(.text*)
    } > FLASH

    .bss : {
        *(.bss*)
    } > FLASH

    .data : {
        *(.data*)
    } > FLASH AT > RAM

    /* Heap for FreeRTOS dynamic allocation */
    .heap :
    {
        . = ALIGN(8);         /* 8-byte alignment for heap */
        _sheap = .;           /* Start of heap */
        . = . + 0x800;        /* Reserve 2 KB for heap */
        . = ALIGN(8);
        _eheap = .;           /* End of heap */
    } >RAM


    __StackTop = ORIGIN(RAM) + LENGTH(RAM);
    PROVIDE(__stack = __StackTop);

}
