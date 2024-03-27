.model small
.stack 100h
.data 
msg1 db 10,"Enter number : $"
.code
main proc
        mov ax,@data
        mov ds,ax
        mov ah,9
        mov dx,offset msg1
        int 21h
        mov ah,1
        int 21h
        sub al,30h
        mov cx,0
        mov cl,al
        mov bl,1
        mov ah,2
        mov bh,al
        mov dl,10
        int 21h
        l1:
        
        mov dl,' '
        space:
        int 21h
        loop space
        mov cl,bl
        
        l2:
        mov dl,'*'
        int 21h
        mov dl,' '
        int 21h
        loop l2
        
        mov dl,10
        int 21h
        mov dl,13
        int 21h
        add bl,1
        mov cl,bh
        dec bh
        loop l1
        mov ah,4ch
        int 21h
main endp
end main
