.model small
.stack 100h
.data

.code
main proc

    mov cx,3
    mov dx,5

    add dx,cx

    add dx,'0'
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h

main endp
end main