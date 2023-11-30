	org 000h ;Starting at address 0000h
	ajmp start
	org 30h
start:
	MOV R6, #48H
	MOV R5, #2AH
	MOV  A, R6     
	SWAP A        
	CPL  A
	MOV R0, #05H        
	XCHD A, @R0
	end
