.model small
.stack 100h
.data
exp1 db 'I am James Bond, 007. I was born in 1920.$'
exp2 db 50 dup (?)
exp3 db 50 dup (?)
len dw 41
.code
main proc
mov ax,@data
mov ds,ax

    mov si,offset exp1
    mov di,offset exp2
    mov bx,offset exp3
    mov cx,len

    l1:
    mov dl,[si]
    cmp dl,'0'
    je l2
    mov dl,[si]
    cmp dl,'1'
    je l2
    mov dl,[si]
    cmp dl,'2'
    je l2
    mov dl,[si]
    cmp dl,'3'
    je l2
    mov dl,[si]
    cmp dl,'4'
    je l2
    mov dl,[si]
    cmp dl,'5'
    je l2
    mov dl,[si]
    cmp dl,'6'
    je l2
    mov dl,[si]
    cmp dl,'7'
    je l2
    mov dl,[si]
    cmp dl,'8'
    je l2
    mov dl,[si]
    cmp dl,'9'
    je l2
    mov dl,[si]
    mov [bx],dl
    inc bx
    jmp ex
    l2:
        mov dl,[si]
        mov [di],dl
        ; inc di
        ; mov dl,','?
        ; mov exp2[di],dl
        inc di
        jmp ex
    ex:
        inc si
    loop l1
    mov exp2[di],'$'
    mov [bx],'$'

    mov dx,offset exp2
    mov ah,9
    int 21h
    mov dl,10
    mov ah,2
    int 21h
    mov dx,offset exp3
    mov ah,9
    int 21h

mov ah,4ch
int 21h

main endp
end main

