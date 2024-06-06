.model small
.stack 100h

.data
A db 01011b
B db 01101b
sum db 0
min db 0
prod db 1
qution db 0
reminder db 0

addr dw ?
.code
main proc
    mov ax,@data
    mov ds,ax

    mov ax,0
    mov al,A
    mov bl,B

    add al,bl       ;;parity and auxaliry is on, beacuse a carry moved from one nibble to another, and number 1s are even

    mov sum,al

    mov al,A
    sub bl,al       ;;no flag is on
    mov min,bl
    mov bl,B
    mul bl
    mov prod,al     ;;no flag on
    
    mov al,B
    mov bl,A

    div bl          ;; no flag on

    mov qution, al
    mov reminder, ah

    

    mov ah,4ch
    int 21h
main endp
end main
