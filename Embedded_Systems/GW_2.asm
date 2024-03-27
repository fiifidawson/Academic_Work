	ORG 00H
	SJMP START
	ORG 20H
START: 
	CLR P2.0
BACK:   CLR P2.1
	CLR P2.2
	CLR P2.3
	;CLR P1.0
REPEAT:	MOV C, P1.0
	JC BACK
	SETB P2.0
	ACALL DELAY
	SETB P2.1
	ACALL DELAY
	SETB P2.2
	ACALL DELAY
	AJMP REPEAT
DELAY:	MOV R0, #0AH
PAN:	MOV R1, #02H
DAT:	MOV R2, #02H
	DJNZ R2, $
	DJNZ R1, DAT
	DJNZ R0, PAN
	RET
	END