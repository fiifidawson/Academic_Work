	ORG 0000H
	AJMP START
	ORG 20H
START:
	MOV R1, #00H
	MOV DPTR, #100H
REPEAT: MOVX A, @DPTR
	INC A
	MOVX @DPTR, A
	INC DPTR
	CJNE DPL, #00 REPEAT
	END