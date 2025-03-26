MEMORY
{
    MEM : ORIGIN = 0x0, LENGTH = 0x8000
}

SECTIONS
{
    .text : {
        *(.vectors*)
        *(.text*)
    } > MEM
}
