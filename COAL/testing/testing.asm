.model small
.stack 100h
.data

.code
main proc
    mov ax, @data
    mov ds, ax

    mov ax,22
    mov bx,10
    div bx
    
    mov ah,4ch
    int 21h
main endp
end main
