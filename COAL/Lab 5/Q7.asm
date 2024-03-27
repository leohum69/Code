.model small
.stack 100h
.data

msg1 db 1,2,3,4,5

.code
main proc

    mov ax,@data
    mov ds,ax

    mov si,offset msg1

    mov cx,5
    mov ax,0

    l1:
    add ax,[si]
    inc si

    loop l1

    aam
    mov cl,al
    mov ch,ah

    mov dl,ch
    add dl, 48
    mov ah,02h
    int 21h

    mov dl,cl
    add dl, 48
    mov ah,02h
    int 21h


    mov ah,4ch
    int 21h

main endp
end main