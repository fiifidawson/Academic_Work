	org 000h ;Starting at address 0000h
	ajmp start
	org 30h
start:
	SETB P0.7
	SETB P0.5
	SETB P0.3
	SETB P0.1
	CLR P0.6
	CLR P0.4
	CLR P0.2
	CLR P0.0
	MOV A, P0
	end
