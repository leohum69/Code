OUTP MACRO X
	MOV DL,X
	MOV AH,02H
	INT 21H
ENDM
.MODEL SMALL
.STACK 100h
.DATA
	gameName db "             CANDY CRUSH$"
	MENU DB         "            Main Menu          ", 10,13,"$"
	player db "Enter name: $"
	pname db 20 DUP(0)
	fname db "record.txt"
	fhandle dw ?
	random db 0
	welcome db "WELCOME$"
	COUNT DB 0
	X DW 0
	Y DW 0
	BOARD DB 49 DUP(0)
	YLINE DB 0
	VAR DW 0
	VAR2 DW 0

	MOVES DB 0
	LEVEL DB "LEVEL:$"
	LEVELNUM DB 0
	SCORESTR DB "Score:$"
	SCORE DB 0
	MOVESSTR DB "Moves:$"
	GETX DW 0
	GETY DW 0
	INDEX1 DB 0
	INDEX2 DB 0
	GETX1 DW 0
	GETY1 DW 0
	NUMBER DB 0
	REGBL DB 0
	INVALID DB "INVALID MOVE$"
	CANDYCOUNT DB 0
	CANDYTYPE DB 0
	PNAME_LEN DB 0
	VALID DB 0
	COMBO DB 0
	newlinestr db 10, 13, '$'
	crushing db "SUGAR CRUSH$"
	exploded DB "EXPLOSION", '$'
	colorbomb db 0
	matches db 0
	
	PRESSZERO db 10,13,"       Enter 0 to Exit game $"
	
	DOTTED db "       -----------------------", 10,13,"$"
	tag db       "       |       LEVEL: $"      
	SUCCESS DB  "      LEVEL SUCCESS $"
	FAILURE DB  "      LEVEL FAILED $"
.CODE
main proc
	MOV AX,@DATA
	MOV DS,AX
	
	MOV AH,3CH 		;3ch: file creation, 3eh: file closes
	MOV CL,0		;to enter read only mode
	
	MOV DX, OFFSET FNAME
	INT 21H
	MOV FHANDLE,AX
	
	MOV AH,00H     ;setting video mode
	MOV AL,0Dh   ;320x200 pixels and 16 colours
	INT 10H
	
	
	MOV AH,0BH
	MOV BH,00H
	MOV BL,04H 	;background colour
	INT 10H

	MOV AH,06h	;scroll-up window
	MOV AL,0
	MOV BH,24H		;text and background colour
	MOV CH,0		;upper row number	
	MOV CL,0		;left col
	MOV DH,24
	MOV DL,79
	INT 10H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,8		;displays message in line 8
	MOV DL,2		;starts display with a gap of 2 spaces
	INT 10H
	
	MOV DX, offset gameName	;displays GAME NAME
	MOV AH,09H
	INT 21H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,15	 ;displays message in line 15
	MOV DL,1	;starts displaying Enter the player name with 8 spaces
	INT 10H
	
	MOV DX, offset player		;displaying enter player name
	MOV AH,09H
	INT 21H
		
	
	MOV SI, OFFSET pname		;to store player name
	.REPEAT
		INC PNAME_LEN
		MOV AH,01
		INT 21H
		MOV AH,0
		MOV [SI],AL
		inc SI
	.UNTIL AL== 13			;takes input for player name till user presses enter key
	mov byte ptr [SI], 36		;'$' sign to make string output better
	
				
				;writing name in .txt file
	MOV AH,3DH 		;3dh write mode
	MOV CL,2		;to read or write
	INT 21H
	
	MOV CX, LENGTHOF PNAME
	MOV BX,fhandle	;File handler moves into AX as soon as file is opened
	MOV DX,OFFSET pname
	MOV AH,40H
	INT 21H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,21		;displays message in line 21
	MOV DL,8		;starts display with a gap of 8 spaces
	INT 10H
	
	MOV DX, offset WELCOME	;displays WELCOME MESSAGE
	MOV AH,09H
	INT 21H
		
	MOV AH,08H
	INT 21H
	
	
	
	
		
	.REPEAT
		CALL MAINMENU_PAGE
		MOV AH,08H
		INT 21H
		SUB AL,48
		MOV LEVELNUM,AL
		.IF AL == 1
			MOV LEVELNUM,1
			MOV AH,05H		;MOVE TO NEXT PAGE WITH BOARD DISPLAY
			MOV AL,03H
		
			MOV AH,0BH
			MOV BH,02H
			MOV BL,0H 	;background colour
			INT 10H
	
			MOV AH,06h	;scroll-up window
			MOV AL,0
			MOV BH,00H		;text and background colour
			MOV CH,0		;upper row number	
			MOV CL,0		;left col
			MOV DH,24
			MOV DL,79
			INT 10H
	
			CALL LEVEL1
		.ELSEIF AL == 2
			MOV LEVELNUM,2
			MOV AH,05H		;MOVE TO NEXT PAGE WITH BOARD DISPLAY
			MOV AL,04H
		
			MOV AH,0BH
			MOV BH,02H
			MOV BL,0H 	;background colour
			INT 10H
	
			MOV AH,06h	;scroll-up window
			MOV AL,0
			MOV BH,00H		;text and background colour
			MOV CH,0		;upper row number	
			MOV CL,0		;left col
			MOV DH,24
			MOV DL,79
			INT 10H
			
			CALL LEVEL2			
			
		.ELSEIF AL == 3
		
			MOV LEVELNUM,3
			MOV AH,05H		;MOVE TO NEXT PAGE WITH BOARD DISPLAY
			MOV AL,05H
	
			MOV AH,0BH
			MOV BH,02H
			MOV BL,0H 	;background colour
			INT 10H
	
			MOV AH,06h	;scroll-up window
			MOV AL,0
			MOV BH,00H		;text and background colour
			MOV CH,0		;upper row number	
			MOV CL,0		;left col
			MOV DH,24
			MOV DL,79
			INT 10H
	
			CALL  LEVEL3
		.ENDIF
		
		CALL CLS
		MOV AH,00
		MOV AL,13
		INT 10H
		MOV AH,05H		;MOVE TO NEXT PAGE WITH BOARD DISPLAY
		MOV AL,06H
		
		MOV AH,06h	;scroll-up window
		MOV AL,0
		MOV BH,00H		;text and background colour
		MOV CH,0		;upper row number	
		MOV CL,0		;left col
		MOV DH,24
		MOV DL,79
		INT 10H
			
		MOV AH,02H
		MOV BH,0
		MOV DH,12
		MOV DL,14
		INT  10H
		.IF SCORE >150		
			LEA DX,SUCCESS		;SCREEN DISPLAYS LEVEL SUCCESS
			MOV AH,09H
			INT 21H
		.ELSE
			LEA DX,FAILURE		;SCREEN DISPLAYS LEVEL FAILED
			MOV AH,09H
			INT 21H
		.ENDIF
		mov ah,08h 
		int 21h
		
		
		CALL CLS
		MOV AH,00
		MOV AL,13
		INT 10H
		
	.UNTIL LEVELNUM==0
	
	
	MOV AH,0		;EXITS VIDEO MODE
	INT 16H
	MOV AH,03
	INT 10h 
	
	MOV AH,3EH		;closes file
	MOV BX,FHANDLE
	INT 21H

	mov ah, 4ch 
	int 21h 
main endp

;************************************
;MAIN MENU PAGE
;****************************************
MAINMENU_PAGE  PROC USES  AX BX CX DX 
	
	MOV AH,05H		;DISPLAYS THIRD PAGE WITH MENU
	MOV AL,02H
	
	MOV AH,0BH
	MOV BH,00H
	MOV BL,04H 	;background colour
	INT 10H

	MOV AH,06h	;scroll-up window
	MOV AL,0
	MOV BH,04H		;text and background colour
	MOV CH,0		;upper row number	
	MOV CL,0		;left col
	MOV DH,24
	MOV DL,79
	INT 10H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,4		;displays message in line 8
	MOV DL,2		;starts display with a gap of 2 spaces
	INT 10H
	
	
	LEA DX,MENU
	MOV AH,09H
	INT 21H
	
	CALL NL
	CALL NL

	LEA DX,DOTTED
	MOV AH,09H
	INT 21H
	
	LEA DX,TAG
	MOV AH,09H
	INT 21H
	
	OUTP '1'
	
	MOV CX,6
	pic:
	
		OUTP ' '
	loop pic
	OUTP '|'
	CALL NL
	
	LEA DX,DOTTED
	MOV AH,09H
	INT 21H
	
	CALL NL
	
	LEA DX,DOTTED
	MOV AH,09H
	INT 21H
	
	LEA DX,TAG
	MOV AH,09H
	INT 21H
	
	OUTP '2'
	
	MOV CX,0
	.WHILE CX<6
		OUTP ' '
		INC CX
	.ENDW
	OUTP '|'
	CALL NL
	
	LEA DX,DOTTED
	MOV AH,09H
	INT 21H
	
	CALL NL
	CALL NL
	
	LEA DX,DOTTED
	MOV AH,09H
	INT 21H
	
	LEA DX,TAG
	MOV AH,09H
	INT 21H
	
	OUTP '3'
	
	MOV CX,0
	.WHILE CX<6
		OUTP ' '
		INC CX
	.ENDW
	OUTP '|'
	CALL NL
	
	LEA DX,DOTTED
	
		
	MOV AH,09H
	INT 21H
	
		LEA DX,PRESSZERO
	MOV AH,09H
	INT 21H
	
	
	RET
MAINMENU_PAGE ENDP
;*********************************************
;NEXT LINE
;*********************************************
NL PROC USES AX DX
	MOV DL,10
	MOV AH,02H
	INT 21H
	MOV DL,13
	MOV AH,02H
	INT 21H
	RET	
NL ENDP
;*********************************************
;GETS RANDOM NUMBER USING SYSTEM TIME
;*********************************************
RAND PROC USES AX BX CX DX
	MOV AH,0
	MOV AL, 0
	INT 1AH
	MOV random,DL
	RET
RAND ENDP

;*******************************************
;CONSTRUCTS BLOCK BORDER FOR EACH CELL 
;*******************************************
BLOCK_BORDER PROC USES AX BX CX DX
	MOV AH,0CH
	MOV AL,0FH
	MOV BX,X
	ADD BX,30
	MOV CX,X
	.WHILE CX<=BX		;constructs two parallel horizontal nice
		MOV DX,Y
		INT 10H
		ADD DX,20
		INT 10H
		INC CX	
	.ENDW
	MOV BX,Y
	ADD BX,20
	MOV DX,Y
	.WHILE DX<=BX		;constructs two vertical lines
		MOV CX,X
		INT 10H
		ADD CX,30
		INT 10H
		INC DX	
	.ENDW
	RET
BLOCK_BORDER ENDP
;********************************************
;initializes board using random function
;********************************************
INITIALIZE_BOARD PROC USES SI AX
	MOV COUNT,0
	MOV SI,OFFSET BOARD		;address of board
	MOV AX,0
	.REPEAT
		CALL RAND			;repeats random function
		MOV AL,COUNT			
		XOR random,AL		;random generated number is randomized even more xor
		MOV AL,random
		MOV AH,0
		MOV BL,5			;taking mod of 5
		DIV BL
		MOV BYTE PTR [SI],AH
		INC SI
		INC COUNT
	.UNTIL COUNT==49
	RET	
INITIALIZE_BOARD ENDP
;******************************************
;FUNCTION CALL FOR DARK BLUE SQUARE CANDY
;********************************************
SQR PROC USES AX BX CX DX
	MOV AH,0CH		;function call for drawing pixels
	MOV AL,01H		;selecting dark blue color
	MOV BH,01
	MOV BX,X
	ADD BX,20		;x-axis range
	MOV CX,X
	ADD CX,10
	MOV DX,Y
	ADD DX,5
	MOV YLINE,DL
	ADD YLINE,10		;y-axis range
	.WHILE CX<BX
		MOV DX,Y
		ADD DX,5
		INT 10H
		.WHILE DL<YLINE		;nested loop
			INC DX
			INT 10H
		.ENDW
		INC CX	
	.ENDW
	RET
SQR ENDP

;******************************************
;FUNCTION CALL FOR PEACH RECTANGLE CANDY
;*******************************************
RECT PROC USES AX BX CX DX
	MOV AH,0CH		;function call for drawing pixel
	MOV AL,0CH		;peach color
	MOV BH,01
	MOV BX,X
	ADD BX,20		;x-axis range
	MOV CX,X
	ADD CX,10
	MOV DX,Y
	ADD DX,5
	MOV YLINE,DL
	ADD YLINE,10		;y-axis range
	.WHILE CX<BX
		MOV DX,Y
		ADD DX,5
		INT 10H
		.WHILE DL<YLINE		;nested loop
			INC DX
			INT 10H
		.ENDW
		INC CX	
	.ENDW
	RET
RECT ENDP
;**************************************
;FUNCTION CALL FOR RED HEART CANDY
;**************************************
HEART PROC USES AX BX CX DX
	
	MOV AH,0CH		;function call for drawing pixels
	MOV AL,04H		;RED colour
	MOV BH,01
	MOV BX,X
	ADD BX,20		;x-axis range
	MOV CX,X
	ADD CX,10
	MOV DX,Y
	ADD DX,5
	MOV YLINE,DL
	ADD YLINE,10		;y-axis range
	.WHILE CX<BX
		MOV DX,Y
		ADD DX,5
		INT 10H
		.WHILE DL<YLINE		;nested loop
			INC DX
			INT 10H
		.ENDW
		INC CX	
	.ENDW
	RET
HEART ENDP
;********************************************
;FUNCTION CALL FOR CYAN TRIANGLE CANDY
;*******************************************
TRIANGLE PROC USES AX BX CX DX
	MOV AH,0CH		;function call for drawing pixels
	MOV AL,0BH	
		MOV BH,01
	MOV BX,X
	ADD BX,20		;x-axis range
	MOV CX,X
	ADD CX,10
	MOV DX,Y
	ADD DX,5
	MOV YLINE,DL
	ADD YLINE,10		;y-axis range
	.WHILE CX<BX
		MOV DX,Y
		ADD DX,5
		INT 10H
		.WHILE DL<YLINE		;nested loop
			INC DX
			INT 10H
		.ENDW
		INC CX	
	.ENDW
	RET
TRIANGLE ENDP
;***************************************
;FUNCTION CALL FOR YELLOW DIAMOND CANDY
;***************************************
DIAMOND PROC
		MOV AH,0CH		;function call for drawing pixels
	MOV AL,0EH	
		MOV BH,01
	MOV BX,X
	ADD BX,20		;x-axis range
	MOV CX,X
	ADD CX,10
	MOV DX,Y
	ADD DX,5
	MOV YLINE,DL
	ADD YLINE,10		;y-axis range
	.WHILE CX<BX
		MOV DX,Y
		ADD DX,5
		INT 10H
		.WHILE DL<YLINE		;nested loop
			INC DX
			INT 10H
		.ENDW
		INC CX	
	.ENDW
	RET
DIAMOND ENDP
;*********************************
;FUNCTION CALL FOR COLOUR BOMB
;********************************
BOMB PROC USES AX BX CX DX
	MOV AH,0CH		;drawing pixels
	MOV AL,00H
	MOV BH,01
	MOV BX,X
	ADD BX,20		;x-axis range
	MOV CX,X
	ADD CX,10
	MOV DX,Y
	ADD DX,5
	MOV YLINE,DL
	ADD YLINE,10			;y-axis range
	.WHILE CX<BX			;draws vertical lines
		MOV AH,0CH
		INC AL
		MOV DX,Y
		ADD DX,5
		INT 10H
		.WHILE DL<YLINE
		INC DX
		INT 10H
		.ENDW
		INC CX	
	.ENDW
	RET
BOMB ENDP
;***************************
;FUNCTION CALL FOR BLOCKAGE
;******************************
BLOCKAGE PROC USES AX BX CX DX
	MOV AH,0CH
	MOV AL,0fH
	MOV BX,X
	ADD BX,25
	MOV CX,X
	ADD CX,5
	MOV DX,Y
	.WHILE CX<BX			;printing diagonal left to right
		INT 10H
		INC CX
		INC DX		
	.ENDW
	MOV BX,X
	ADD BX,5
	MOV CX,X
	ADD CX,25
	MOV DX,Y
	.WHILE CX>BX			;printing diagonal righ to left
		INT 10H
		DEC CX
		INC DX		
	.ENDW
	RET
BLOCKAGE ENDP
;*****************************************
;function to highlight selected BLOCK
;***********************************
HIGHLIGHT PROC USES AX BX CX DX
	MOV AH,0CH
	MOV AL,0fH
	MOV BX,X
	ADD BX,25
	MOV CX,X
	ADD CX,2				;same as block border with different diensions
	.WHILE CX<=BX
		MOV DX,Y
		ADD DX,2
		INT 10H
		INC DX
		ADD DX,17
		INT 10H
		INC CX	
	.ENDW
	MOV BX,Y
	ADD BX,17
	MOV DX,Y
	ADD DX,2
	.WHILE DX<=BX
		MOV CX,X
		ADD CX,2
		INT 10H
		ADD CX,25
		INT 10H
		INC DX	
	.ENDW
	RET
HIGHLIGHT ENDP

;*************************************************
;FUNCTION CALL FOR DISPLAYING LEVEL DETAILS
;**********************************************
LEVEL_DETAILS PROC USES AX BX CX DX
	MOV AH,06h	;scroll-up window
	MOV AL,0
	MOV BH,00H		;text and background colour
	MOV CH,0		;upper row number	
	MOV CL,0		;left col
	MOV DH,24
	MOV DL,79
	INT 10H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,2	;displays message in line 8
	MOV DL,2		;starts display with a gap of 2 spaces
	INT 10H
	
	MOV DX, offset gameName	;displays gamename
	MOV AH,09H
	INT 21H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,4		;displays message in line 4
	MOV DL,29		;starts display with a gap of 29 spaces
	INT 10H
	
	MOV DX, offset LEVEL	;displays the word 'LEVEL'
	MOV AH,09H
	INT 21H
	
	MOV DL, LEVELNUM	;displays level number
	ADD DL,48
	MOV AH,02H
	INT 21H
	
	MOV AH,02H
	MOV BH,0
	MOV DH,6		;displays message in line 6
	MOV DL,29		;starts display with a gap of 29 spaces
	INT 10H
	
	MOV SI,OFFSET pname
	MOV CL,0
	.WHILE CL<PNAME_LEN
		MOV DL,BYTE PTR [SI]
		MOV AH,02H
		INT 21H
		INC SI
		INC CL
	.ENDW
	
	MOV AH,02H
	MOV BH,0
	MOV DH,8		;displays message in line 8
	MOV DL,29		;starts display with a gap of 29 spaces
	INT 10H
	
	MOV DX, offset MOVESSTR	;displays the word 'Moves'
	MOV AH,09H
	INT 21H
	
	MOV DL,MOVES	;displays moves
	MOV NUMBER,DL
	CALL DISPLAYNUM
	
	OUTP '/'
	OUTP '1'
	OUTP '5'		;total moves for each level
	
	MOV AH,02H
	MOV BH,0
	MOV DH,10		;displays message in line 10
	MOV DL,29		;starts display with a gap of 29 spaces
	INT 10H
	
	MOV DX, offset SCORESTR			;displays the word 'Score'
	MOV AH,09H
	INT 21H
	
	MOV DL,SCORE	;displays moves
	MOV NUMBER,DL
	CALL DISPLAYNUM
	
	RET
LEVEL_DETAILS ENDP

;FUNCTION CALL FOR DISPLAYING BOARD AS PER ARRAY

DISPLAYBOARD PROC USES SI  AX
	MOV COUNT,0
	MOV SI,OFFSET BOARD
	MOV X,10
	MOV Y,30
	.WHILE COUNT<49
	MOV Al, [SI]
		.IF AL!=5
		CALL BLOCK_BORDER
		.ENDIF
		.IF aL==0
			CALL SQR
		.ELSEIF AL==1
			CALL RECT
		.ELSEIF AL==2
			CALL HEART
		.ELSEIF AL==3
			CALL TRIANGLE
		.ELSEIF AL==4
			CALL DIAMOND
		
		.ELSEIF AL==6
			CALL BOMB
		.ENDIF
		INC SI
		ADD X,30
		.IF X>=220
			MOV X,10
			ADD Y,20
		.ENDIF
		INC COUNT
	.ENDW
	RET
DISPLAYBOARD ENDP

;***********************************************
;FUNCTION CALL FOR INITIALIZING BOARD FOR LEVEL3
;************************************************
LEVEL3_BOARD PROC USES SI
	MOV SI,OFFSET BOARD
	MOV COUNT,3
	ADD SI,3
	.WHILE COUNT<=49 		;vertically putting blockage
		MOV BYTE PTR [SI],5
		ADD SI,7
		ADD COUNT,7
	.ENDW
	MOV SI,OFFSET BOARD
	MOV COUNT,21
	ADD SI,21
	.WHILE COUNT<28
		MOV BYTE PTR [SI],5		;horizontally putting blockage
		INC SI
		INC COUNT
	.ENDW
	RET
LEVEL3_BOARD ENDP
;**************************************************
;FUNCTION CALL FOR INITIALIZING BOARD FOR LEVEL2
;****************************************************
LEVEL2_BOARD PROC USES SI
	MOV SI,OFFSET BOARD
	MOV BYTE PTR [SI],5			;hardcoding blockage as per level 2
	ADD SI,3
	MOV BYTE PTR [SI],5
	ADD SI,3
	MOV BYTE PTR [SI],5

	INC SI
	MOV BYTE PTR [SI],5
	ADD SI,6
	MOV BYTE PTR [SI],5

	ADD SI,8
	MOV BYTE PTR [SI],5

	ADD SI,6
	MOV BYTE PTR [SI],5
	ADD SI,8
	MOV BYTE PTR [SI],5
	ADD SI,6
	MOV BYTE PTR [SI],5
	INC SI
	MOV BYTE PTR [SI],5

	MOV BYTE PTR [SI],5
	ADD SI,3
	MOV BYTE PTR [SI],5
	ADD SI,3
	MOV BYTE PTR [SI],5
	RET
LEVEL2_BOARD ENDP
;*************************************************
;GETS X AND Y COORDINATES WHEN MOUSE IS CLICKED
;**************************************************
getcoordinates proc uses AX BX CX DX
	MOV AX,1		;puts cursor on the screen 
	INT 33H
	MOV CX, 20
	MOV DX, 440
	MOV AX, 7
	INT 33H
	MOV CX, 30
	MOV DX, 170
	MOV AX, 8
	INT 33H
	.REPEAT
		MOV AX,3		;gets cursor co-ordinates
		INT 33H
		MOV GETX,CX  	;moves x-coordinate into getx variable
		MOV GETY,DX 	;moves y-coordinate into gety variable
		MOV CX,0H		;ADDING DELAY
		MOV DX,0FFFFH
		MOV AH,86H
		INT 15H
	.UNTIL BL==1	;until button click detected
	MOV DX,0
	MOV AX,GETX
	MOV BX,2		;in 320x200 mode, value of cx is doubled so we halve it
	DIV BX
	MOV GETX,AX
	RET
getcoordinates endp
;******************************************
;OUTPUTS MULTI DIGIT NUMBER
;**************************************
DISPLAYNUM PROC USES AX BX CX DX
	MOV AX,0
	MOV AL,NUMBER
    MOV CX, 0
    .WHILE AX>0
        MOV DX, 0
        MOV BX, 10	;dividing by 10
        DIV BX
        PUSH DX		;pushing into stack
        INC CX
    .ENDW
    .WHILE CX!=0
        POP DX			;pops in reverse order
        ADD DX, 30h
        MOV AH, 2H;
        INT 21H
        DEC CX
    .ENDW
    RET
DISPLAYNUM ENDP
;***********************************************
;GETS INDEX OF ARRAY FOR SAID CO-ORDINATES
;********************************************
CHECK_BLOCK PROC USES AX BX CX DX		
	MOV COUNT,0				;translates coordinates into block
	MOV X,10
	MOV CX,GETX
	.WHILE X<CX			;while x is less than mouse coordinates
		INC COUNT		;incrementing for index
		ADD X,30
	.ENDW
	SUB X,30
	MOV Y,20
	MOV CX,GETY			;yy-coordinate get by mouse
	MOV BX,0
	.WHILE Y<CX			;getting y index
		INC BX
		ADD Y,20
	.ENDW
	SUB Y,10
	CALL HIGHLIGHT		;selected block is highlighted
	MOV AX,7
	DEC BX
	MUL BX
	ADD COUNT,AL
	DEC COUNT
	
	RET
CHECK_BLOCK ENDP



;SCORE UPDATE

SCORE_UPDATE PROC USES AX BX
	MOV AX,0
	MOV AL,CANDYCOUNT
	.IF CANDYTYPE==0		;one square has 1 point
		MOV BL,1
		MUL BL
	.ELSEIF CANDYTYPE==1		;a rectangle has 2 points
		MOV BL,2
		MUL BL
	.ELSEIF CANDYTYPE==2		;heart has 3 points
		MOV BL,3
		MUL BL
	.ELSEIF CANDYTYPE==3		;triangle has 2 points
		MOV BL,2
		MUL BL
	.ELSEIF CANDYTYPE==4		;diamond has 1 point
		MOV BL,1
		MUL BL
	.ENDIF
	ADD SCORE,AL
	RET
SCORE_UPDATE ENDP
;*************
;CHECKS FOR MATCHES
;*************
CHECK_FOR_MATCHES PROC USES SI DI AX BX CX DX
	mov matches, 0
	MOV COMBO,0
	MOV SI,OFFSET BOARD
	MOV COUNT,0
	MOV AL,BYTE PTR [SI]
	MOV CANDYTYPE, AL
	MOV CANDYCOUNT,1
	.WHILE COUNT <49		;checking for horizontal matches
		INC SI
		MOV AL,CANDYTYPE
		.IF [SI]==AL		;if candy matches
			INC CANDYCOUNT		;increment counter
		.ELSE 
			MOV CL,CANDYCOUNT
			.IF CANDYCOUNT>=3 && CANDYTYPE!=5  	;if 3 candies of same type have been found
				mov matches, 1
				CALL SCORE_UPDATE		;score uppdate after crushing candy
				MOV DI,SI
				.REPEAT
					DEC DI
					MOV BYTE PTR [DI],7
					DEC CANDYCOUNT
					MOV COMBO,1
				.UNTIL CANDYCOUNT==0
			.ENDIF
			.IF CL==5	&& CANDYTYPE !=5 && LEVELNUM !=3	;incase of 5 candies matching a color bomb is added to the board
				SUB SI,3
				MOV BYTE PTR [SI],6
				ADD SI,3
			.ENDIF
			MOV CANDYCOUNT,1		;resetting count
			MOV AL,[SI]
			MOV CANDYTYPE,AL
		.ENDIF
		INC COUNT
	.ENDW
	MOV CANDYCOUNT,1
	MOV AX,0
	.WHILE AL<7
		MOV SI,OFFSET BOARD
		MOV DX,0
		MOV DL,AL
		ADD SI,DX
		MOV BL,BYTE PTR [SI]
		MOV CANDYTYPE,BL
		MOV AH,0
		.WHILE AH<7
			ADD SI,7
			.IF BL == BYTE PTR [SI]		;if candy matches
				INC CANDYCOUNT			;increment counter
			.ELSE
				MOV CL,CANDYCOUNT
				.IF CANDYCOUNT>=3 && CANDYTYPE !=5			;if 3 candies of same type have been found
					mov matches, 1
					CALL SCORE_UPDATE
					MOV DI,SI
					.REPEAT
						SUB DI,7
						MOV BYTE PTR [DI],7
						MOV DL,BYTE PTR [DI]
						DEC CANDYCOUNT
						MOV COMBO,1
					.UNTIL CANDYCOUNT==0
				.ENDIF
				.IF CL==5 && CANDYTYPE !=5 && LEVELNUM !=3				;incase of 5 candies matching a color bomb is added to the board
					SUB SI,21
					MOV BYTE PTR [SI],6
					ADD SI,21
				.ENDIF
				MOV CANDYCOUNT,1 		;resetting count
				MOV BL,BYTE PTR [SI]
				MOV CANDYTYPE,BL
			.ENDIF
			INC AH
		.ENDW
		INC AL
	.ENDW
	RET
CHECK_FOR_MATCHES ENDP
;***********************************
;CHECKS IF MOVE IS VALID OR NOT
;*************************************
VALIDITY PROC USES AX BX CX DX SI
	MOV AX,0
	MOV BX,0
	MOV AL,INDEX1
	MOV BL,INDEX2
	MOV SI,OFFSET BOARD		;moving address of board
	ADD SI,AX
	.IF BYTE PTR [SI]==5			;checking if either of the indices point to blockage 
		JMP INVALID1
	.ENDIF
	MOV SI,OFFSET BOARD
	ADD SI,BX
	.IF BYTE PTR [SI]==5
		JMP INVALID2
	.ENDIF
	MOV COUNT,0
	INC AX
	.IF AX==BX
		INC COUNT
	.ENDIF
	SUB AX,2
	.IF AX==BX
		INC COUNT
	.ENDIF
	MOV AL,INDEX1
	ADD AX,7
	.IF AX==BX
		INC COUNT
	.ENDIF
	MOV AL,INDEX1
	SUB AX,7
	.IF AX==BX
		INC COUNT
	.ENDIF
	.IF COUNT==0			;if counter hasnt been incremented even once move is invalid
		INVALID2:
		INVALID1:

		MOV AH,02H
		MOV BH,0
		MOV DH,15		;displays message in line 15
		MOV DL,28		;starts display with a gap of 29 spaces
		INT 10H
	
		MOV DX, offset INVALID	;displays 'INVALID MOVE'
		MOV AH,09H
		INT 21H
		MOV VALID,1
	.ENDIF
	RET
VALIDITY ENDP
;*******************************
;SWAPS THE SELECTED CANDIES
;********************************
SWAP PROC USES SI DI AX BX
						;swaps both indices using SI and DI 
	MOV SI,OFFSET BOARD
	MOV BX,0
	MOV BL,INDEX1
	ADD SI,BX
	MOV AL,BYTE PTR[SI]
	MOV DI,OFFSET BOARD
	MOV BL,INDEX2
	ADD DI,BX
	MOV AH,BYTE PTR [DI]
	MOV [SI],AH
	MOV [DI],AL

	RET
SWAP ENDP
;****************************************************
;CHECKS WHETHER USER SELECTED THE COLOR BOMB OR NOT 
;*****************************************************
CHECK_FOR_COLORBOMB PROC USES SI DI BX CX 
	mov colorbomb, 0
	MOV SI,OFFSET BOARD
	MOV DI,OFFSET BOARD
	MOV BX,0
	MOV BL,INDEX1
	ADD SI,BX
	MOV BL,INDEX2
	ADD DI,BX
	.IF BYTE PTR [SI]==6		;checks if either of selected indces are color bombs or not
		MOV CL,BYTE PTR[DI]
		MOV CANDYTYPE,CL
		MOV BYTE PTR [SI],7
		MOV VALID,1
	.ELSEIF BYTE PTR [DI]==6		;checks if either of selected indces are color bombs or not
		MOV CL,BYTE PTR[SI]
		MOV CANDYTYPE,CL
		MOV BYTE PTR [DI],7
		MOV VALID,1
	.ELSE
		JMP OVER			;in case of no color bomb
	.ENDIF
	mov colorbomb, 1
	
	MOV COUNT,0
	MOV CANDYCOUNT,0
	MOV CL, CANDYTYPE
	MOV SI,OFFSET BOARD
	.WHILE COUNT<49		;traversing through entire array
		.IF BYTE PTR[SI]==CL		;if candy is found
			MOV BYTE PTR [SI],7		;candy popped
			INC CANDYCOUNT			
		.ENDIF
		INC COUNT
		INC SI
	.ENDW
	INC MOVES
	CALL SCORE_UPDATE		;score is updated
	OVER:
	RET
CHECK_FOR_COLORBOMB ENDP
;**************************************
;REPOPULATE BOARD TO PUT NEW CANDIES
;***************************************
REPOPULATE PROC USES SI
	MOV COUNT,0
	MOV SI,OFFSET BOARD
	.WHILE COUNT<49		;board is traversed
		.IF BYTE PTR [SI]==7 || BYTE PTR [SI]==5		;in case of blockage 5 or empty space 7 new candies are brought
			MOV AX,0
			CALL RAND		;random number generated
			MOV AL,random
			XOR AL,COUNT		;number is randomized even more
			MOV BL,5
			DIV BL
			MOV BYTE PTR [SI],AH
		.ENDIF
		INC SI
		INC COUNT
	.ENDW
		RET
REPOPULATE ENDP
;*********************************************
;DROP CANDIES
;***********************************************
DROP_CANDIES PROC USES SI CX
	MOV SI,OFFSET BOARD
	MOV COUNT,0
	.WHILE COUNT <49			;entire array is traversed
		.IF BYTE PTR [SI]==7 && COUNT>=7		;in case of empty space found
			MOV CL, COUNT
			MOV INDEX1,CL
			SUB CL,7
			MOV INDEX2,CL
			.REPEAT				;it is brought up to the top most row
				CALL SWAP
				SUB INDEX1,7
				SUB INDEX2,7
			.UNTIL INDEX1<7
		.ENDIF
		INC SI
		INC COUNT
	.ENDW
	RET
DROP_CANDIES ENDP
;*****************************************
;LEVEL 1 game
;********************************************
LEVEL1 PROC USES AX BX CX DX
	MOV MOVES,1
	MOV SCORE,0
	CALL INITIALIZE_BOARD

	.REPEAT
		MOV AH,00H
		MOV AL,13
		INT 10H
		CALL REPOPULATE
		MOV CH,0
		.REPEAT
				CALL CHECK_FOR_MATCHES
				CALL DROP_CANDIES
				CALL REPOPULATE
				INC CH
		.UNTIL COMBO==0 || CH==6
		CALL LEVEL_DETAILS
		CALL DISPLAYBOARD
		CALL getcoordinates
		CALL CHECK_BLOCK
		MOV CL,COUNT
		MOV INDEX1,CL
		MOV CX,5H		;ADDING DELAY
		MOV DX,0FFFFH
		MOV AH,86H
		INT 15H
	
		CALL getcoordinates
		CALL CHECK_BLOCK
		MOV CL,COUNT
		MOV INDEX2,CL 
		
		CALL VALIDITY
		CALL CHECK_FOR_COLORBOMB
		.IF VALID==1
			MOV VALID,0
			JMP OVER
		.ENDIF
				
		CALL SWAP
		CALL CHECK_FOR_MATCHES
	
		INC MOVES
		OVER:
		CALL DROP_CANDIES
		MOV CX,7H		;ADDING DELAY
		MOV DX,0FFFFH
		MOV AH,86H
		INT 15H
		.IF colorbomb==1
			xor ax, ax
			mov ah, 2h
			mov bh, 0
			mov dh, 15
			 mov dl, 28
			 int 10h
			mov DX, offset exploded
			MOV AH,09H
			INT 21H
				MOV CX,5H		;ADDING DELAY
				MOV DX,0FFFFH
				MOV AH,86H
				INT 15H
		.ELSE
			.IF matches==1
				xor ax, ax
				mov ah, 2h
				mov bh, 0
				mov dh, 15
				mov dl, 28
				int 10h
				mov dx, offset crushing
				mov ah, 9h
				int 21h
				MOV CX,5H		;ADDING DELAY
				MOV DX,0FFFFH
				MOV AH,86H
				INT 15H
			.ENDIF
		.ENDIF
		.IF moves!=15
			CALL CLS
		.ENDIF
		
	.UNTIL MOVES==15

	RET
	
LEVEL1 ENDP
;**************
;LEVEL 2 game
;**************
LEVEL2 PROC USES AX BX CX DX
	MOV MOVES,1
	MOV SCORE,0
	CALL INITIALIZE_BOARD
	CALL LEVEL2_BOARD
	.REPEAT
	MOV AH,00H
	MOV AL,13
	INT 10H
	MOV CH,0
		.REPEAT
				CALL CHECK_FOR_MATCHES
				CALL DROP_CANDIES
				CALL REPOPULATE
				CALL LEVEL2_BOARD
				INC CH
		.UNTIL COMBO==0 || CH==6
	CALL LEVEL_DETAILS
	CALL DISPLAYBOARD
	CALL getcoordinates
	CALL CHECK_BLOCK
	MOV CL,COUNT
	MOV INDEX1,CL
	MOV CX,5H		;ADDING DELAY
	MOV DX,0FFFFH
	MOV AH,86H
	INT 15H
	
	CALL getcoordinates
	CALL CHECK_BLOCK
	MOV CL,COUNT
	MOV INDEX2,CL 
	MOV CX,5H		;ADDING DELAY
	MOV DX,0FFFFH
	MOV AH,86H
	INT 15H
	CALL VALIDITY
	CALL CHECK_FOR_COLORBOMB
	.IF VALID==1
		MOV VALID,0
		JMP OVER
	.ENDIF
	CALL SWAP
	CALL CHECK_FOR_MATCHES

	INC MOVES
	OVER:
	CALL DROP_CANDIES
	MOV CX,2H		;ADDING DELAY
	MOV DX,0FFFFH
	MOV AH,86H
	INT 15H
	.IF colorbomb==1
			xor ax, ax
			mov ah, 2h
			mov bh, 0
			mov dh, 15
			 mov dl, 28
			 int 10h
			mov DX, offset exploded
			MOV AH,09H
			INT 21H
				MOV CX,5H		;ADDING DELAY
				MOV DX,0FFFFH
				MOV AH,86H
				INT 15H
		.ELSE
			.IF matches==1
				xor ax, ax
				mov ah, 2h
				mov bh, 0
				mov dh, 15
				mov dl, 28
				int 10h
				mov dx, offset crushing
				mov ah, 9h
				int 21h
				MOV CX,5H		;ADDING DELAY
				MOV DX,0FFFFH
				MOV AH,86H
				INT 15H
			.ENDIF
		.ENDIF
	.IF moves!=15
	CALL CLS
	.ENDIF
	.UNTIL MOVES==15
	RET
LEVEL2 ENDP

CANDY PROC
MOV DX, OFFSET gamename
mov ah, 9h 
int 21
ret 
CANDY endp

SUGARCRUSH proc

MOV AH, 02h 
MOV DL, 3    
INT 21h      

MOV AH, 02h  
MOV DL, 13  
INT 21h      

MOV AH, 02h  
MOV DL, 10   
INT 21h   
ret 
SUGARCRUSH ENDP



;LEVEL 3 game
LEVEL3 PROC USES AX BX CX DX
	MOV MOVES,1
	MOV SCORE,0
	CALL INITIALIZE_BOARD
	CALL LEVEL3_BOARD
	.REPEAT
	MOV AH,00H
	MOV AL,13
	INT 10H
	MOV CH,0
		.REPEAT
				CALL CHECK_FOR_MATCHES
				CALL DROP_CANDIES
				CALL REPOPULATE
				CALL LEVEL3_BOARD
				INC CH
		.UNTIL COMBO==0 || CH==6
	CALL LEVEL_DETAILS
	CALL DISPLAYBOARD
	CALL getcoordinates
	CALL CHECK_BLOCK
	MOV CL,COUNT
	MOV INDEX1,CL
	MOV CX,5H		;ADDING DELAY
	MOV DX,0FFFFH
	MOV AH,86H
	INT 15H
	
	CALL getcoordinates
	CALL CHECK_BLOCK
	MOV CL,COUNT
	MOV INDEX2,CL 
	MOV CX,5H		;ADDING DELAY
	MOV DX,0FFFFH
	MOV AH,86H
	INT 15H
	CALL VALIDITY
	CALL CHECK_FOR_COLORBOMB
	.IF VALID==1
		MOV VALID,0
		JMP OVER
	.ENDIF
	CALL SWAP
	CALL CHECK_FOR_MATCHES

	INC MOVES
	OVER:
	CALL DROP_CANDIES
	MOV CX,2H		;ADDING DELAY
	MOV DX,0FFFFH
	MOV AH,86H
	INT 15H
	.IF colorbomb==1
			xor ax, ax
			mov ah, 2h
			mov bh, 0
			mov dh, 15
			 mov dl, 28
			 int 10h
			mov DX, offset exploded
			MOV AH,09H
			INT 21H
				MOV CX,5H		;ADDING DELAY
				MOV DX,0FFFFH
				MOV AH,86H
				INT 15H
		.ELSE
			.IF matches==1
				xor ax, ax
				mov ah, 2h
				mov bh, 0
				mov dh, 15
				mov dl, 28
				int 10h
				mov dx, offset crushing
				mov ah, 9h
				int 21h
				MOV CX,5H		;ADDING DELAY
				MOV DX,0FFFFH
				MOV AH,86H
				INT 15H
			.ENDIF
		.ENDIF
	.IF moves!=15
	CALL CLS
	.ENDIF
	.UNTIL MOVES==15
	RET
LEVEL3 ENDP



SWEET PROC
MOV AH, 02h 
MOV DL, 3    
INT 21h      

MOV AH, 02h  
MOV DL, 13  
INT 21h      

MOV AH, 02h  
MOV DL, 10   
INT 21h 
MOV AH, 02h  
MOV DL, 13  
INT 21h      

MOV AH, 02h  
MOV DL, 10   
INT 21h     
ret 

SWEET ENDP
;CLEAR SCREEN

CLS PROC
	MOV AL,03
	MOV AH,0
	INT 10H
	RET
CLS ENDP
END MAIN