ORG 0000H
REPEAT:
	CLR P0.0
BACK: 
	MOV C, P1.0
	ACALL DELAY
	JC REPEAT
	SETB P0.0
	AJMP BACK
DELAY:
	MOV R0, #00H
NN1:
	MOV R1, #00H
HERE:
	DJNZ R1, HERE
	DJNZ R0, NN1
	RET
END
	