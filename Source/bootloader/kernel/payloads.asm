phase_1:
    call playsound

    mov ax, 0xa000
    mov es, ax
    xor di, di
    mov cx, 64000
.bg:
    in al, 0x40
    and al, 0x1F
    stosb
    loop .bg

    mov si, msg
    call print_string_center
    inc byte [timer]
    jmp end_frame

phase_2:
    call stopsound

    mov ax, 0xa000
    mov es, ax
    xor di, di
.draw:
    mov ax, di
    mov bx, WSCREEN
    xor dx, dx
    div bx          ; ax=y, dx=x
    and al, dl
    add al, [timer]
    stosb
    cmp di, 64000
    jne .draw
    
    mov si, msg
    call print_string_center
    inc byte [timer]
    jmp end_frame

phase_3:
    mov ax, 0xa000
    mov es, ax
    xor di, di
.draw:
    mov ax, di
    mov bx, WSCREEN
    xor dx, dx
    div bx          ; ax=y, dx=x
    xor al, dl
    add al, [timer]
    stosb
    cmp di, 64000
    jne .draw
    
    mov si, msg
    call print_string_center
    inc byte [timer]
    jmp end_frame

phase_4:
    mov ax, 0xa000
    mov es, ax
    xor di, di
    xor cx, cx      ; y
.y:
    xor dx, dx      ; x
.x:
    mov ax, dx
    add ax, [word_timer]
    mov si, cx
    add si, [word_timer]
    imul ax, si
    and al, 0x3F
    stosb
    inc dx
    cmp dx, WSCREEN
    jne .x
    inc cx
    cmp cx, HSCREEN
    jne .y
    
    mov si, msg
    call print_string_center
    inc word [word_timer]
    jmp end_frame