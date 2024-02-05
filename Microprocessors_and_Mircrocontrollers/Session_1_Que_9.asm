	org 000h ;Starting at address 0000h
	ajmp start
	org 30h
start:
	MOV 30h, #58h
	
	MOV A, 30H
	MOV C, ACC.4 ; #30h is byte addressable so move it to 20h but addressable
	CLR A
	MOV acc.2, C
	END
	
	