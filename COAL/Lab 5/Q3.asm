.model small
.stack 100h
.data

array db "abcdefghijklmnopqrstuvwxyz"

.code
main proc

    mov ax,@data
    mov ds,ax

    mov si,offset array
    add si,25
    mov cx,26
    mew2:
    mov dl,[si]
    mov ah,02h
    int 21h
    dec si
    loop mew2
    mov ah,4ch
    int 21h

main endp
end main