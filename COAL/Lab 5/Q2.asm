.model small
.stack 100h
.data

array db 1,2,3,4,5,6,7,8,9

.code
main proc

    mov ax,@data
    mov ds,ax

    mov si,offset array
    mov cx,9
    mew2:
    mov dl,[si]
    add dl,'0'
    mov ah,02h
    int 21h
    inc si
    loop mew2
    mov ah,4ch
    int 21h

main endp
end main