.model small
.stack 100h
.data
exp1 db 'Enter The Number in caps : $'
exp2 db 'Decimal : $'
num db 0
num2 db 0

.code
main proc
mov ax,@data
mov ds,ax

    mov dx,offset exp1
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    mov bl,al
    mov num,bl
    cmp bl,'A'
    je l1
    mov num,bl
    cmp bl,'B'
    je l2
    mov num,bl
    cmp bl,'C'
    je l3
    mov num,bl
    cmp bl,'D'
    je l4
    mov num,bl
    cmp bl,'E'
    je l5
    mov num,bl
    cmp bl,'F'
    je l6

    sub bl,'0'
    jmp ex

    l1:
        mov bl,10d
        jmp ex
    l2:
        mov bl,11d
        jmp ex
    l3:
        mov bl,12d
        jmp ex
    l4:
        mov bl,13d
        jmp ex
    l5:
        mov bl,14d
        jmp ex

    l6:
        mov bl,15d
        jmp ex

    ex:
    mov ax,0
    mov al,bl
    mov bl,16d
    mul bl
    mov bl,al
    mov num,bl

    mov ah,1
    int 21h
    mov bl,al
    mov num2,bl
    cmp bl,'A'
    je l7
    mov num2,bl
    cmp bl,'B'
    je l8
    mov num2,bl
    cmp bl,'C'
    je l9
    mov num2,bl
    cmp bl,'D'
    je l0
    mov num2,bl
    cmp bl,'E'
    je la
    mov num2,bl
    cmp bl,'F'
    je lb

    sub bl,'0'
    jmp ex2

    l7:
        mov bl,10d
        jmp ex2
    l8:
        mov bl,11d
        jmp ex2
    l9:
        mov bl,12d
        jmp ex2
    l0:
        mov bl,13d
        jmp ex2
    la:
        mov bl,14d
        jmp ex2

    lb:
        mov bl,15d
        jmp ex2

    ex2:

    add num,bl
    mov dl,num

    mov dl,10
    mov ah,2
    int 21h
    
    mov dx,offset exp2
    mov ah,9
    int 21h

    mov al,num
    aam
    mov cl,al
    mov al,ah
    mov ah,0
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
    mov dl,cl
    add dl,'0'
    mov ah,2
    int 21h


mov ah,4ch
int 21h

main endp
end main

