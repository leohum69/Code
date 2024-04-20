.model small
.stack 100h
.data
msg1 db 'Enter The Number : $'
num dw 0
adr dw 0
count db 0
.code
factors proc
    pop adr
    pop cx
    ; push dx
    mov bl,0
    mov ax,cx
    l1:
    inc bl
    div bx
    mov ax,cx

    cmp dx,0
    je l2
    y:
    mov dx,0
    cmp bx,cx
    jnz l1
    jmp ex
    l2:
    push bx
    inc count
    jmp y

    ex:
    push adr
    ret 2
factors endp

print proc
    mov adr,0
    pop adr
    mov cl,1
    l3:
    cmp cl,count
    jz n
    inc cl
    mov dl,10
    mov ah,2
    int 21h
    pop ax
    aam
    mov bh,ah
    mov bl,al
    mov dl,bh
    add dl,30h
    mov ah,2
    int 21h
    mov dl,bl
    add dl,30h
    mov ah,2
    int 21h
    jmp l3
    n:
    push adr
    ret 2
print endp

main proc
    mov ax,@data
    mov ds,ax 

    mov dx,offset msg1
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    sub al,30h
    mov ah,0
    mov bl,10
    mul bl
    mov cl,al
    mov ah,1
    int 21h
    sub al,30h
    add cl,al
    mov num,cx
    mov cx,0
    push num
    call factors
    mov ax,0
    call print 

    mov ah,4ch
    int 21h
main endp
end main