	org 000
	ajmp start
	org 30h
start:
	MOV R0, #45H
	MOV 20h, R0
	CLR P3.3
	MOV C, 06H
	MOV P3.3, C
	CLR A
	MOV A, P3
	END
	