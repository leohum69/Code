.model small
.stack 100h

.data
    msg1   db 10,13,'Enter Marks of Student : $'
    msg2   db 10,13,'Total Marks : $'
    msg3   db 10,13,'Percentage : $' 
    total  dw 0010,0010,0010,0010,0010
    res    dw 0
    count  dw 5

.code
main proc
               mov  ax, @data
               mov  ds, ax

               mov  cx, count
               mov  si, offset total
    input_loop:
               mov  dx, offset msg1
               mov  ah, 09h
               int  21h

               mov  ah, 01h
               int  21h

               sub  al, 30h
               mov  bh,10
               mul  bh
               mov  bh,al
                   
               mov  ah, 01h
               int  21h

               sub  al, 30h
                 
               mov  bl,al
               add  bl,bh
               mov  bh,0
               mov  [si], bx
               inc  si
               loop input_loop

               mov  si, offset total
               mov  ax, 0
               mov  cx,count
    calc_loop: 
               add  al,[si]
               inc  si
               loop calc_loop
               mov  dx, offset msg2
               mov  bx,ax
               mov res,bx

               mov  ah, 09h
               int  21h
               
               mov  ax,bx
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

               mov dx,offset msg3
               mov ah,9
               int 21h

               mov ax,res
               mov bl,5
               div bl
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
               


               mov  ah, 4ch
               int  21h
main endp
end main
