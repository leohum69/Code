.model small
.stack 100h
.data

msg1 db 1,2,3,4,5,6

len = ($-msg1)

msg2 db 10,13,"e$"
msg3 db 10,13,"o$"
.code
main proc

    mov ax,@data
    mov ds,ax

    mov cx,len
    mov si,offset msg1

    l1:
    mov al,[si]
    inc si
    and al,01h

    jz ev
    
    mov dx,offset msg3
    mov ah,09h
    int 21h
    jmp y

    ev:
    mov dx,offset msg2
    mov ah,09h
    int 21h
    y:

    loop l1

    mov ah,4ch
    int 21h

main endp
end main