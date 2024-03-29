.model small
.stack 100h
.data
arr1 db 3 dup(?)
msg1 db 'Enter Number 1 :$'
msg2 db 'Enter Number 2 :$'
msg3 db 'Enter Number 3 :$'
sum db 0
.code
square proc
    push bp
    mov bp,sp
    add bp,4
    mov si,[bp]

    mov cx,3
    l1:
    mov ax,0
    mov al,[si]
    mul al
    mov [si],al
    inc si
    loop l1
    pop bp
    ret 2
square endp

main proc
    mov ax,@data;mov ax, 12
    mov ds,ax

    mov si,offset arr1

    mov dx,offset msg1
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    sub al,30h
    mov [si],al

    mov dl,10
    mov ah,2
    int 21h

    mov dx,offset msg2
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    sub al,30h
    mov [si+1],al

    mov dl,10
    mov ah,2
    int 21h

    mov dx,offset msg3
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    sub al,30h
    mov [si+2],al

    mov dl,10
    mov ah,2
    int 21h

    push si

    call square
    mov si,offset arr1
    mov cx,3
    mov ax,0
    l2:
    mov al,[si]
    add sum,al
    inc si
    loop l2

    mov al,sum
    aam
    mov ch,ah
    mov cl,al
    add ch,30h
    add cl,30h
    mov dl,ch
    mov ah,2
    int 21h
    mov dl,cl
    mov ah,2
    int 21h


    mov ah,4ch
    int 21h
main endp
end main
