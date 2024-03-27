.model small
.stack 100h

.data
    msg1   db 10,13,'Enter price of item $'
    msg2   db 10,13,'Total bill: $'
    total dw 5 dup(?)
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


               mov  ah, 4Ch
               int  21h
main endp
end main
