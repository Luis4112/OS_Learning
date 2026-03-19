ENTRY(kernel_main)
     Sections {
	. = 0x10000;

	.text : { *(.text)}
	
	.data : { *(.data)}
}
