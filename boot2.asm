[org 0x7c00]


jmp start




;---GDT----

gdt_start:

gdt_null:
dd 0x0
dd 0x0


gdt_code:
dw 0xFFFF
dw 0x0
db 0x0
db 10011010b
db 11001111b
db 0x0

;---- END GDT



start:






;---- Padding and BIOS signature-----

times 510-($-$$) db 0
dw 0xAA55
