.model small
.stack 100h
.data
msg1 db 'hello world$'
.code
lowp proc
    push bp
    mov bp,sp
    add bp,4
    mov si,[bp]

    mov cx,11
    l1:
        mov al,[si]
        sub al,20h
        mov [si],al
        inc si
    loop l1
    mov si,[bp]
    ; mov [si+5],' '
    pop bp
    ret 2
lowp endp

main proc
    mov ax,@data
    mov ds,ax
    mov si,offset msg1
    push si
    call lowp
    mov dx,offset msg1
    mov ah,9
    int 21h

    mov ah,4ch
    int 21h
main endp
end main