clsscreen macro		;clear screen
	call mkscreen
endm

pushreg macro		; push registers

	push di
	push si
	push ax
	push bx
	push cx
	push dx

endm

popreg macro		; pop registers

	pop dx
	pop cx
	pop bx
	pop ax
	pop si
	pop di

endm

calsleep macro msec		;sleep code for parameter ms

	pushreg
	mov cx,0	
	
	.while cx < msec
		
		mov dx,1
		push dx
		call sleep
		inc cx
	
	.endw
	
	popreg

endm



setcurs macro x,y	;set curser to x y cord

	pushreg
	mov ah,02h
	mov dl,x
	mov dh,y	
	int 010h
	popreg

endm

writefilestr macro stringOffset		;write string in file

	pushreg
	mov dx,stringOffset
	
	sub sp,2
	push dx
	call StrLen
	pop cx
	
	mov ah,040h
	int 021h
	popreg

endm

coutnum macro number	;couts

	pushreg
	mov dx,number
	push dx
	call output
	popreg

endm

coutstr macro stringOffset

	pushreg
	mov dx,stringOffset
	mov ah,09h
	int 21h
	popreg

endm