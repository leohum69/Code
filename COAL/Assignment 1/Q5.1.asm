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
        mov bx,0
        mov cl,al
        mov bl,al
        inc bl
        mov dl,10
        mov ah,2
        int 21h
        l1:

        l2:
        mov dl,"*"
        mov ah,2
        int 21h
        loop l2
        mov dl,10
        mov ah,2
        int 21h
        dec bl
        mov cx,bx

        loop l1



        mov ah,4ch
        int 21h
       

main endp
end main
