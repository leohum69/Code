.model small
.stack 100h
.data
msg1 db 'Enter a 3 digit input (less than 500) : $'
msglose db 'Not a Armstrong Number.$'
msgwin db 'It is a Armstrong Number.$'
arr dw 3 dup(0)
lol dw 0
rem dw 0
address dw ?
.code

check_armstrong proc
    
    pop address
        pop si
        pop ax
        
        cmp ax,100
        jge xd
        
        mov ax,lol
        cmp ax,10
        jge xd2

        mov cx,[si+4]
        mov ax,lol
            cmp cx,ax
            je output1
            mov dx, offset msglose
            mov ah,9
            int 21h
            jmp ex

            output1:
            mov dx, offset msgwin
            mov ah,9
            int 21h
            jmp ex

        jmp ex
        xd:
            mov ax,word ptr [si]
            mov bx,ax
            mul bx
            mul bx
            mov dx,ax
            mov rem,dx
            mov ax,[si+2]
            mov bx,ax
            mul bx
            mul bx
            mov dx,rem
            add dx,ax
            mov rem,dx
            mov ax, [si+4]
            mov bx,ax
            mul bx
            mul bx
            mov dx,rem
            add dx,ax
            mov rem,dx
            mov cx,lol
            cmp cx,dx
            je output1
            mov dx, offset msglose
            mov ah,9
            int 21h
            jmp ex

        jmp ex

        xd2:
            mov ax,[si+2]
            mov bx,ax
            mul bx
            mov dx,rem
            add dx,ax
            mov rem,dx
            mov ax,[si+4]
            mov bx,ax
            mul bx
            mov dx,rem
            add dx,ax
            mov rem,dx
            mov cx,lol
            cmp cx,dx
            je output1
            mov dx, offset msglose
            mov ah,9
            int 21h
            jmp ex
        jmp ex


    ex:
    push address
ret
check_armstrong endp

main proc
    mov ax,@data
    mov ds,ax

    mov dx,offset msg1

    mov ah,9
    int 21h
    mov si,offset arr
    mov dx,0
    mov ah,1
    int 21h
    mov dl,al
    sub dl,'0'
    mov dh,0
    mov [si],dx
    inc si
    inc si
    mov bl,100
    mov ax,0
    mov al,dl
    mul bl
    mov lol,ax

    mov ah,1
    int 21h
    mov dl,al
    sub dl,'0'
    mov dh,0
    mov [si],dx
    inc si
    inc si
    mov bl,10
    mov ax,0
    mov al,dl
    mul bl
    mov cx,lol
    add cx,ax
    mov lol,cx
    mov dx,0
    mov ah,1
    int 21h
    mov dl,al
    sub dl,'0'
    mov dh,0
    mov [si],dx
    mov cx,lol
    add cx,dx
    mov lol,cx
    mov dx,10
    mov ah,2
    int 21h
    push cx
    mov si,offset arr 
    push si
    call check_armstrong

    mov ah,4ch
    int 21h
main endp
end main