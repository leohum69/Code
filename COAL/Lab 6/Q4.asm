.model small
.stack 100h
.data
msg0 db 'Enter First number : $'
msg1 db 10,'Enter Second number : $'
msg2 db 10,'Both Equal$'
msg3 db ' is Greater$'
.code
main proc
    mov ax,@data
    mov ds,ax
    mov dx,offset msg0
    mov ah,09
    int 21h
    mov ah,01
    int 21h
    mov bl,al
    sub bl,'0'
    int 21h
    mov dx,offset msg1
    mov ah,09
    int 21h
    mov ah,01
    int 21h
    mov bh,al
    sub bh,'0'
    int 21h

    cmp bh,bl
    jz Equal
    ja Gre
    jb NoGre

    


    Equal:
    mov dx,offset msg2
    mov ah,09
    int 21h
    mov ah,4ch
    int 21h


    NoGre:
    mov dl,bl
    add dl,'0'
    mov ah,02h
    int 21h
    mov dx,offset msg3
    mov ah,09
    int 21h
    mov ah,4ch
    int 21h


    Gre:
    mov dl,bh
    add dl,'0'
    mov ah,02h
    int 21h
    mov dx,offset msg3
    mov ah,09
    int 21h
    mov ah,4ch
    int 21h

main endp
end main