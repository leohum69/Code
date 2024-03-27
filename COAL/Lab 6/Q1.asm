.model small
.stack 100h
.data
    msg1 db 10,13, "Please entre the array for sorting:$"    
    msg2 db 10,13, "Sorted array is:$"
    array db  5 dup(?)
.code

main proc
mov ax, @data
mov ds, ax

;to display the message
mov dx, offset msg1
mov ah, 09h
int 21h

;general register for loop
mov cx, 5
mov bx, offset array

mov ah,1

;loop to take 5 numbers from the user
takeinput:
int 21h
mov [bx], al
inc bx
loop takeinput

mov cx, 5
dec cx


outerloop:
mov bx, cx
mov si, 0

;this loop used to compare the values
compareloop:
mov al, array[si]
mov dl, array[si+1]
cmp al, dl

;jnc -> jump no carry is used for descending order
;jnc noswap

jc noswap
; jc -> jump carry

mov array[si], dl
mov array[si+1], al

noswap:

;if carry is 1 so no swaping its mean value in [si] is already smaller

inc si
dec bx
; no si value is inc from 0 to 1 and bx is decremented by 1 which is 4
jnz compareloop

loop outerloop


;new line

mov ah, 2
mov dl,10
int 21h
mov dl, 13
int 21h

;print after sorting array

mov cx, 5
mov bx, offset array

;loop to display the array element on screen

;to display the message
mov dx, offset msg2
mov ah, 09h
int 21h

;this loop is used to display the value on the screen
loopforoutput:
mov dl, [bx]
mov ah, 2
int 21h

;used these lines to add the space between the numbers
mov dl, 32
mov ah, 2
int 21h

inc bx
loop loopforoutput


mov ah, 4ch
int 21h

main endp
end main