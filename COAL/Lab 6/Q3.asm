.model small
.stack 100h
.data
var db  0,1,2,3,4,5,6,7,8,99
msg1 db 10,'Found$'
msg2 db 10,'Not Found$'
msg0 db 'Enter the number : $'
.code
main proc
    mov ax,@data
    mov ds,ax
    mov dx,offset msg0
    mov ah,09h
    int 21h
    mov ah,01h
    int 21h
    ; mov al,6
    sub al,'0'
    mov cx,10
    mov si,offset var

    search:
    mov bl,[si]
    inc si
    cmp al,bl
    jz lol


    loop search

    mov dx,offset msg2
    mov ah,09h
    int 21h
    mov ah,4ch
    int 21h

    lol:
    mov dx,offset msg1
    mov ah,09h
    int 21h
    mov ah,4ch
    int 21h

main endp
end main