	org 000h ;Starting at address 0000h
	ajmp start
	org 30h
start:
	MOV A, #36H
	MOV R0, A
	CPL, R0
	XRL R0, A
	END