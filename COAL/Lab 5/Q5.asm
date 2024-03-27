.model small
.stack 100h
.data

msg1 db "Enter Number : $"
msg2 db 10,13,"The number is even$"
msg3 db 10,13,"The number is odd$"

.code
main proc

    mov ax,@data
    mov ds,ax

    mov dx,offset msg1
    mov ah,09h
    int 21h

    mov ah,01h
    int 21h

       
    and al,01h
    int 21h

    jz ev
    
    mov dx,offset msg3
    mov ah,09h
    int 21h
    mov ah,4ch
    int 21h


    ev:
    mov dx,offset msg2
    mov ah,09h
    int 21h
    

    mov ah,4ch
    int 21h

main endp
end main