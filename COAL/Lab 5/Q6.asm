.model small
.stack 100h
.data

msg1 db 1,2,3,4,5,6

len = ($-msg1)

msg2 db 10,13,"The number is even$"
msg3 db 10,13,"The number is odd$"
.code
main proc

    mov ax,@data
    mov ds,ax

    mov al,len
    and al,01h
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