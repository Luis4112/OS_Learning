ENTRY(start)

SECTIONS {
    . = 0x100000;

    .text : {
        *(.multiboot)
        boot.o(.text)
        *(text)
        }

    .data : {*(.data)}

    .bss (NOLOAD) : {
        __bss_start = .;
        *(.bss)
        *(COMMON)
        __bss_end = .;
    } 
}
