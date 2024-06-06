.model small
.stack 100h
.data   
    msg1 db 'Original array : $'
    msg2 db 'Sorted array : $'
    array db 42,32,33,52,37,47,51
    addr dw 0
.code
sort proc
    pop addr
        mov cx, 7
        dec cx

        outer:
        mov bx, cx
        mov si, 0
        comploop:
        mov al, array[si]
        mov dl, array[si+1]
        cmp al, dl
        jc nosw
        mov array[si], dl
        mov array[si+1], al
        nosw:
        inc si
        dec bx
        jnz comploop

        loop outer

    push addr
ret
sort endp
main proc
    mov ax, @data
    mov ds, ax

    mov cx, 7
    mov si,offset array
    mov dx,offset msg1
    mov ah,9
    int 21h
    l1:
        mov ax,[si]
        aam
        mov bl,al
        mov dl,ah
        add dl,'0'
        mov ah,2
        int 21h
        mov dl,bl
        add dl,'0'
        mov ah,2
        int 21h

        mov dl,' '
        mov ah,2
        int 21h
        inc si

    loop l1
    call sort

    mov dl,10
    mov ah,2
    int 21h
    mov dx,offset msg2
    mov ah,9
    int 21h
    mov si,offset array
    mov cx,7
    l2:
        mov ax,[si]
        aam
        mov bl,al
        mov dl,ah
        add dl,'0'
        mov ah,2
        int 21h
        mov dl,bl
        add dl,'0'
        mov ah,2
        int 21h

        mov dl,' '
        mov ah,2
        int 21h
        inc si
    loop l2

mov ah, 4ch
int 21h

main endp
end main