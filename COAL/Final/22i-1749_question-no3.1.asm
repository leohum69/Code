.model small
.stack 100h
.data

.code
main proc

    mov dl,'I'
    mov ah,2
    int 21h
    mov dl,' '
    mov ah,2
    int 21h
    mov dl,'L'
    mov ah,2
    int 21h
    mov dl,'o'
    mov ah,2
    int 21h
    mov dl,'v'
    mov ah,2
    int 21h
    mov dl,'e'
    mov ah,2
    int 21h
    mov dl,' '
    mov ah,2
    int 21h
    mov dl,'P'
    mov ah,2
    int 21h
    mov dl,'a'
    mov ah,2
    int 21h
    mov dl,'k'
    mov ah,2
    int 21h
    mov dl,'i'
    mov ah,2
    int 21h
    mov dl,'s'
    mov ah,2
    int 21h
    mov dl,'t'
    mov ah,2
    int 21h
    mov dl,'a'
    mov ah,2
    int 21h
    mov dl,'n'
    mov ah,2
    int 21h
    mov ah,4ch
    int 21h
main endp
end main