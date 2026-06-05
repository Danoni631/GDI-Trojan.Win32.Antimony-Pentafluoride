[bits 16]
[ORG 0x7C00]

jmp bootmain

bootmain:
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    mov ax, 0x13
    int 0x10

%include "SbF7H2_MBR/kernel/kernel.asm"

times 510-($-$$) db 0
dw 0xAA55