.model small
.stack 100h
.data
msg1 db 'Enter 8 Integers : $'
plusms db 'Sum : $'
minms db 'Subtraction : $'
prodms db 'Multiply : $'
divms db 'Divide : $'
inp db 8 dup(?)
plus db ?
min db ?
prod dw ?
quot db ?
.code 
main proc
    mov ax,@data
    mov ds,ax
    mov dx,offset msg1
    mov ah,9
    int 21h
    mov cx,8
    mov si,offset inp
    l1:
    mov ah,1
    int 21h
    sub al,30h
    mov [si],al
    inc si
    loop l1
    mov si,offset inp
    mov ax,0

    mov al,[si]
    add al,[si+1]
    mov plus,al
    mov ax,0

    mov al,[si+2]
    mov bl,[si+3]
    mul bl
    mov prod,ax
    mov ax,0

    mov al,[si+4]
    sub al,[si+5]
    mov min,al
    mov ax,0

    mov al,[si+6]
    mov bl,[si+7]
    div bl
    mov quot,al

    mov dl,10
    mov ah,2
    int 21h

    mov dx,offset plusms
    mov ah,9
    int 21h

    mov dl,plus
    add dl,30h
    mov ah,2
    int 21h

    mov dl,10
    mov ah,2
    int 21h

    mov dx,offset minms
    mov ah,9
    int 21h

    mov dl,min
    add dl,30h
    mov ah,2
    int 21h

    mov dl,10
    mov ah,2
    int 21h

    mov dx,offset prodms
    mov ah,9
    int 21h

    mov dx,prod
    add dl,30h
    mov ah,2
    int 21h

    mov dl,10
    mov ah,2
    int 21h

    mov dx,offset divms
    mov ah,9
    int 21h

    mov dl,quot
    add dl,30h
    mov ah,2
    int 21h

    mov dl,10
    mov ah,2
    int 21h

    mov ah,4ch
    int 21h
main endp
end main