

	CLR 00H
REPEAT:
	MOV C, P1.0
	ACALL DELAY
	JC REPEAT
	ACALL SWITCH
	CPL 00H
	SJMP REPEAT
	
SWITCH:
	MOV C, 00H
	MOV P2.0, C
	RET
	
DELAY: 
	MOV R0, #00H
PALO:	MOV R1, #60H
	
HERE: 	DJNZ R1, HERE
	DJNZ R0, PALO
	RET
	
	
	END