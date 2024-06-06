dosseg
.model small
.stack 100h
.data

.code
main proc

    mov ah,0h
    mov al,5h
    int 10h

    mov ah,0ch 
	mov al,0eh

    mov cx,80
    mov dx,50
    int 10h

    .while cx < 120
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,65
    .while cx < 80
        int 10h
        inc cx
    .endw
    mov cx, 120
    .while cx < 135
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,60
    .while cx < 65
        int 10h
        inc cx
    .endw
    mov cx,135
    .while cx < 140
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,50
    .while cx < 60
        int 10h
        inc cx
    .endw
    mov cx,140
    .while cx < 150
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,45
    .while cx < 50
        int 10h
        inc cx
    .endw
    mov cx,150
    .while cx < 155
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,40
    .while cx < 45
        int 10h
        inc cx
    .endw
    mov cx,155
    .while cx < 160
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,35
    .while cx < 40
        int 10h
        inc cx
    .endw
    mov cx,160
    .while cx < 165
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,35
    .while cx < 40
        int 10h
        inc cx
    .endw
    mov cx,160
    .while cx < 165
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,35
    .while cx < 40
        int 10h
        inc cx
    .endw
    mov cx,160
    .while cx < 165
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,30
    .while cx < 35
        int 10h
        inc cx
    .endw
    mov cx,165
    .while cx < 170
        int 10h
        inc cx
    .endw
    
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
        inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
    inc cx
    .endw
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
    inc dx      ;10 bar copy
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw

    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,20
    .while cx < 25
        int 10h
        inc cx
    .endw
    mov cx,175
    .while cx < 180
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
            inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
    inc cx
    .endw
    inc dx
    mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
    inc dx
        mov cx,25
    .while cx < 30
        int 10h
        inc cx
    .endw
    mov cx,170
    .while cx < 175
        int 10h
        inc cx
    .endw
        inc dx
    mov cx,30
    .while cx < 35
        int 10h
        inc cx
    .endw
    mov cx,165
    .while cx < 170
        int 10h
        inc cx
    .endw
        inc dx
    mov cx,35
    .while cx < 40
        int 10h
        inc cx
    .endw
    mov cx,160
    .while cx < 165
        int 10h
        inc cx
    .endw
        mov cx,35
    .while cx < 40
        int 10h
        inc cx
    .endw
    mov cx,160
    .while cx < 165
        int 10h
        inc cx
    .endw
        mov cx,35
    .while cx < 40
        int 10h
        inc cx
    .endw
    mov cx,160
    .while cx < 165
        int 10h
        inc cx
    .endw
    inc dx
        mov cx,40
    .while cx < 45
        int 10h
        inc cx
    .endw
    mov cx,155
    .while cx < 160
        int 10h
        inc cx
    .endw
    inc dx
        mov cx,45
    .while cx < 50
        int 10h
        inc cx
    .endw
    mov cx,150
    .while cx < 155
        int 10h
        inc cx
    .endw
    inc dx
        mov cx,50
    .while cx < 60
        int 10h
        inc cx
    .endw
    mov cx,140
    .while cx < 150
        int 10h
        inc cx
    .endw
    inc dx
        mov cx,60
    .while cx < 65
        int 10h
        inc cx
    .endw
    mov cx,135
    .while cx < 140
        int 10h
        inc cx
    .endw
    inc dx
        mov cx,65
    .while cx < 80
        int 10h
        inc cx
    .endw
    mov cx, 120
    .while cx < 135
        int 10h
        inc cx
    .endw
    inc dx
    mov cx,80
    int 10h

    .while cx < 120
        int 10h
        inc cx
    .endw
    inc dx

mov ah, 4ch
int 21h
main endp
end main