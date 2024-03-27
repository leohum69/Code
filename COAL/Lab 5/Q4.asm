.model small
.stack 100h
.data

array db "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

.code
main proc

    mov ax,@data
    mov ds,ax

    mov si,offset array
    mov cx,26
    mew2:
    mov dl,[si]
    mov ah,02h
    int 21h
    inc si
    loop mew2
    mov ah,4ch
    int 21h

main endp
end main