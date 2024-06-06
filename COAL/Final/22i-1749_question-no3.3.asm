.model small
.stack 100h
.data
strin db 'Enter a small letter : $'
.code
main proc
    mov ax,@data
    mov ds,ax

    mov dx,offset strin
    mov ah,9
    int 21h
    mov ah,1
    int 21h

    mov cl,al

    sub cl,32d
    mov dl,10
    mov ah,2
    int 21h
    mov dl,cl
    mov ah,2
    int 21h
    

    mov ah,4ch
    int 21h

main endp
end main