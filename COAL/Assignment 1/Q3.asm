.model small
.stack 100h
.data
msg1 db 'Enter The Number in Multi Digit : $'
msg2 db 10,13,'The sum of the first $'
msg3 db ' natural numbers is: $'
num dw 0
.code
main proc
    mov ax,@data
    mov ds,ax

    mov dx,offset msg1
    mov ah,9
    int 21h

    mov ah,1
    int 21h
    mov bx,0
    sub al,'0'
    mov bl,10
    mul bl
    mov bl,al
    mov ah,1
    int 21h
    sub al,'0'
    add bl,al
    mov num,bx
    mov ax,num
    inc ax

    ; mov ax,0
    mov bx,num
    mul bx
    mov bx,2
    div bx
    mov bl,al
    
    mov dx,offset msg2
    mov ah,9
    int 21h
    mov ax,num
    aam
    mov cl,al
    mov ch,ah

    mov dl,ch
    add dl,'0'
    mov ah,2
    int 21h
    mov dl,cl
    add dl,'0'
    mov ah,2
    int 21h

    mov dx,offset msg3
    mov ah,9
    int 21h

    mov ah,0
    mov al,bl
    ; aam
    ; mov cx,0
    ; mov cl,al
    ; mov ch,ah

    ; mov dl,ch
    ; add dl,'0'
    ; mov ah,2
    ; int 21h
    ; mov dl,cl
    ; add dl,'0'
    ; mov ah,2
    ; int 21h
    aam
    mov  bl,al
    mov  al,AH
    mov  ah,0
    aam
               
    mov  cx,ax
    mov  ah, 02h
    mov  dl,ch
    add  dl,30h
    int  21h
    mov  dl,cl
    add  dl,30h
    int  21h
    mov  dl,bl
    add  dl,30h
    int  21h
    mov  dl,10
    int  21h
   mov  dl,13
   int  21h

    mov ah,4ch
    int 21h
main endp
end main