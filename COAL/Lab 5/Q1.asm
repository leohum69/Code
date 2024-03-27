.model small
.stack 100h
.data

msg1 db "Enter First Number : $"
msg2 db 10,13,"Enter Second Number : $"
msg3 db 10,13,"Both Numbers are Equal.$"
msg4 db 10,13,"Both Numbers are not Equal.$"

.code
main proc

    mov ax,@data
    mov ds,ax
    
    mov dx,offset msg1
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h
   
    mov cl,al
    int 21h

    mov dx,offset msg2
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h

    mov ch,al
    int 21h

    cmp cl,ch
    
    je Equal

    mov dx,offset msg4
    mov ah,09h
    int 21h

    mov ah,4ch 
    int 21h

    Equal:
    mov dx,offset msg3
    mov ah,09h
    int 21h

    mov ah,4ch 
    int 21h

main endp
end main