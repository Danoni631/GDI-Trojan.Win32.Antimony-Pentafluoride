main_sequence:
    mov ax, 0x0040
    mov gs, ax
    mov eax, [gs:0x006C]
    sub eax, [start_tick]
    
    cmp eax, 55
    jb phase_1
    cmp eax, 145
    jb phase_2
    cmp eax, 236
    jb phase_3
    cmp eax, 327
    jb phase_4
    cmp eax, 430
    jb reboot
    
    mov eax, [gs:0x006C]
    mov [start_tick], eax
    jmp phase_1

%include "SbF7H2_MBR/graphics/graphics.asm"
%include "SbF7H2_MBR/kernel/payloads.asm"
%include "SbF7H2_MBR/drivers/machine.asm"
%include "SbF7H2_MBR/graphics/print.asm"
%include "SbF7H2_MBR/drivers/audio.asm"
%include "SbF7H2_MBR/kernel/data.asm"