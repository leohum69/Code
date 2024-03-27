.model small
.stack 100h
.data

var db  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99,100

.code
main proc
mov ax,@data
mov ds,ax

    mov cx, 100
    mov si,offset var

    l1:
        mov al,[si]
        and al,01h

    jnz ev

        jmp y

    ev:
        mov al,[si]
        aam
        mov bl,al
        mov bh,ah
        mov dl,bh
        add dl,'0'
        mov ah,02h
        int 21h
        mov dl,bl
        add dl,'0'
        mov ah,2h
        int 21h
        mov dl,' '
        mov ah,2h
        int 21h
    y:
        inc si
    loop l1



    mov ah,4ch
    int 21h

main endp
end main