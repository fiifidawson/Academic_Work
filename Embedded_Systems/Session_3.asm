	ORG 0000H
	AJMP START
	ORG 20H
START:
	MOV R2, #3
	MOV R0, #13H
REPEAT: INC @R0
	INC R0
	DJNZ R2, REPEAT
	END