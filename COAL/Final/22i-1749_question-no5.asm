.model small
.stack 100h

.data
; str1 db 3 dup(?)
; str2 db 8 dup(?)
str1 db 'ABD'
str2 db 'ABACADACD'
msg1 db 'Enter SUBST : $'
msg2 db 'Enter MAINST : $'

msgwin db 'SUBST IS A SUBSTRING OF MAINST$'
msglose db 'SUBST IS NOT A SUBSTRING OF MAINST$'
.code
main proc
    mov ax,@data
    mov ds,ax

    mov dx,offset msg1
    mov ah,9
    int 21h
    mov cx,3
    mov si,offset str1
    l1:
        mov ah,1
        int 21h
        mov [si],al
        inc si
    loop l1
    mov dx,10
    mov ah,2
    int 21h
    mov dx,offset msg2
    mov ah,9
    int 21h
    mov cx,8
    mov si,offset str2
    l2:
        mov ah,1
        int 21h
        mov [si],al
        inc si
    loop l2

    mov dl,0
    mov si,offset str2
    mov di,si
    l3:
    mov di,si
    add di,dx
    mov al,[di]
    mov bl,str1[0]
    cmp al,bl
    je lol
    inc dx
    cmp dx,6
    jne l3
    jmp ex
    lol:
        mov di,si
        add di,dx
        add di,1
        mov al,[di]
        mov bl,str1[1]
        cmp al,bl
        je xd
        inc dx
        jmp l3
            xd:
            mov di,si
            add di,dx
            add di,2
            mov al,[di]
            mov bl,str1[2]
            cmp al,bl
            je xd2
            inc dx
            jmp l3
                xd2:
                mov dx,10
                mov ah,2
                int 21h
                mov dx,0
                mov dx,offset msgwin
                mov ah,9
                int 21h
                jmp ex2
    jmp l3
    ex:
    mov dx,10
    mov ah,2
    int 21h
    mov dx,0
    mov dx,offset msglose
    mov ah,9
    int 21h
    jmp ex2

    ex2:
    mov ah,4ch
    int 21h
main endp
end main