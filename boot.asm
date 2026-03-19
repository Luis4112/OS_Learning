;----- Mem Map--------
; Memory map 0x9000
; stack ceiling 0x90000 PE
; Paging 0x1000
; bootloader 0x7C00
; Page Table 0 0x2000

;----End Mem Map---------
[org 0x7C00]

jmp start


;---GDT start--------------
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


gdt_data:
dw 0xFFFF
dw 0x0
db 0x0
db 10010010b
db 11001111b
db 0x0

gdt_end:

gdt_descriptor:

dw gdt_end - gdt_start - 1
dd gdt_start


;---Entry Point-----------------
start:
mov edi, 0x9000
xor ebx, ebx

.loop:
mov eax, 0xE820
mov ecx, 24
mov edx, 0x534D4150
int 0x15
jc .done
add edi, 24
test ebx, ebx
jnz .loop
.done:
cli
lgdt [gdt_descriptor]

mov eax, cr0
or eax, 0x1
mov cr0, eax
jmp 0x08:protected_mode

[bits 32]
protected_mode:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov fs, ax
    mov gs, ax
    mov esp, 0x90000

;-----page dir------
mov edi, 0x1000
mov dword [edi], 0x2003

; Page table - looping for 1024 entries.
mov eax, 0x0000
mov ecx, 1024
mov edi, 0x2000

pt_loop:
mov dword [edi], eax
or dword [edi], 0x3
add edi, 4
add eax, 0x1000
loop pt_loop

;----page pointing and enabling-----

mov eax, 0x1000
mov cr3, eax

mov eax, cr0
or eax, 0x80000000
mov cr0, eax

mov dword [0xB8000], 0x0F420F41
hlt




;------Padding and signature---------
times 510-($-$$) db 0
dw 0xAA55
