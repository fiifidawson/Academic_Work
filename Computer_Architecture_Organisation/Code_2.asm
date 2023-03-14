;MOV AX, 1234H
;MOV BX, 5678H
;MOV CX, 9ABCH   

;MOV AL, 65H

;MOV AX, 1234H
;MOV DH, 24H
;HLT

;MOV AX, 1234H
;MOV DH, 24H 
;MOV BL, DH
;MOV CX, AX
 
;MOV AX, 0B800h; set AX to hexadecimal value of B800h
;mov ds, ax; copy value of AX to DS
;MOV CH, 1101_1111B; set CH to binary value
;MOV BX, 15Eh; set BX to 15Eh 

;MOV AX, 037AH
;MOV DS, AX 
;MOV CL, 1110_1100B
;MOV BX, 15EH
;MOV [BX], CX     


;MOV AX, 047AH
;MOV DS, AX
;MOV CL, 1110_1101B
;MOV BX, 15EH
;MOV [BX], CX
;MOV DL, [BX];Copy byte from memory at [BX] to DL


MOV AX, 1A3AEH