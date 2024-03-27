ORG 0000H
loop1:
	CLR P0.0
BACK: 
	MOV C, P1.0
	ACALL delay
	JC loop1
	SETB P0.0
	AJMP BACK
delay:
	MOV R0, #00H
loop2:
	MOV R1, #00H
loop3:
	DJNZ R1, loop3
	DJNZ R0, loop2
	RET
END
	