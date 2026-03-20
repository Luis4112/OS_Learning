ENTRY(kernel_main)

SECTIONS {
    . = 0x10000;

    .text : {*(.text)}

    .data : {*(.data)}

    .bss (NOLOAD) : {
        __bss_start = .;
        *(.bss)
        *(COMMON)
        __bss_end = .;
    } 
}
