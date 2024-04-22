.model small
.stack 100h
.data
num db 0
exp1 db 'Enter The Number : $'
fail db 'fail$'
.code
main proc
mov ax,@data
mov ds,ax

    mov dx, offset exp1
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    mov bl,al
    sub bl,'0'
    mov ax,0
    mov al,bl
    mov bl,10
    mul bl
    mov bl,al
    mov ah,1
    int 21h
    sub al,'0'
    add bl,al

    mov dl,10
    mov ah,2
    int 21h

    mov num,bl
    cmp bl,85
    jg l1
    mov num,bl
    cmp bl,80
    jg l2
    mov num,bl
    cmp bl,75
    jg l3
    mov num,bl
    cmp bl,70
    jg l4
    mov num,bl
    cmp bl,65
    jg l5
    mov num,bl
    cmp bl,60
    jg l6
    mov dx,offset fail
    mov ah,9
    int 21h
    jmp exit


    l1:
        mov dl,'A'
        mov ah,2
        int 21h
        jmp exit
    l2:
        mov dl,'A'
        mov ah,2
        int 21h
        mov dl,'-'
        mov ah,2
        int 21h
        jmp exit
    l3:
        mov dl,'B'
        mov ah,2
        int 21h
        mov dl,'+'
        mov ah,2
        int 21h
        jmp exit
    l4:
        mov dl,'B'
        mov ah,2
        int 21h
        jmp exit
    l5:
        mov dl,'B'
        mov ah,2
        int 21h
        mov dl,'-'
        mov ah,2
        int 21h
        jmp exit
    l6:
        mov dl,'C'
        mov ah,2
        int 21h
        mov dl,'+'
        mov ah,2
        int 21h
        jmp exit

    


exit:

    mov ah,4ch
    int 21h

main endp
end main

