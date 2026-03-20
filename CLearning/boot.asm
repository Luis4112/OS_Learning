global start
extern kernel_main


section .multiboot
dd 0x1BADB002
dd 0x0
dd - ( 0x1BADB002)


section .text
bits 32

start:
    call kernel_main

hang:
    hlt
    jmp $
