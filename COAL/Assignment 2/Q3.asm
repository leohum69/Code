.model small
.stack 100h
.data
inp db 7 dup(?)
.code
main proc
    mov ax,@data
    mov ds,ax

    mov cx,7
    mov si,offset inp

    p1:
    mov ah,1
    int 21h
    sub al,30h
    mov [si],al
    inc si
    loop p1

    mov ax,0
    mov si,offset inp
    ; jmp l3
    mov al,[si+6]
    cmp al,[si+5]
    je l1
    mov al,[si+4]
    cmp al,[si+3]
    jne l1
    jmp exit

    l1:
    mov al,[si+6]
    cmp al,[si+3]
    je l2
    mov al,[si+5]
    cmp al,[si+4]
    jbe l2
    jmp exit

    ;first if ended

    l2:
    mov al,[si]
    cmp al,[si+6]
    jna exit

    mov al,[si+1]
    cmp al,[si+4]
    jbe l3
    jmp exit
    ;2nd if ended
    l3:
    mov al,[si+2]
    cmp al,[si]
    jna exit
    mov al,[si+4]
    cmp al,[si+2]
    jae l4
    jmp exit

    l4:
    mov dl,10
    mov ah,2
    int 21h
    mov dl,[si]
    add dl,30h
    mov ah,2
    int 21h

    exit:
    mov ah,4ch
    int 21h
main endp
end main