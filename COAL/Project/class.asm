maxMoves = 5
lvl1thresh = 250
lvl2thresh = 100
lvl3thresh = 150
tarueeeeee = 1
falaseeeeeeee = 0
Zeroo = 0
bswidth = 50
bsheight = 20
candywid = 30
candyhei = 12
boardWidth = 7
boardHeight = 7
candy_type equ <word>
candy_type_NULL = 0
candy_type_1 = 1
candy_type_2 = 2
candy_type_3 = 3
candy_type_4 = 4
candy_type_5 = 5
candy_type_Bomb = 6
candy_type_First = candy_type_1
candy_type_Last = candy_type_Bomb
randSleepTime = candy_type_Last * 10
usernameSize = 20
coord struct

	x word 0
	y word 0

coord ends

candy struct

	topLeftCoord coord <>
	shapeType candy_type candy_type_NULL
	rowNum word 0
	colNum word 0
	InCombo word falaseeeeeeee

candy ends

boardsqr struct

	topLeftCoord coord <>
	currentCandy Candy <>
	IsSelected word falaseeeeeeee

boardsqr ends