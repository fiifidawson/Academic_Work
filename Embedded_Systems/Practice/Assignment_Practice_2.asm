;;OP Jump Page 99

; Q1
;	MOV R3, #0D5h
; 	MOV A, R3
;LOOP:   INC R3            
;        MOV A, R3         
;	CJNE A, #0E1h, LOOP
;        END

; Q3
;	MOV R4, #0F1h
; 	MOV A, R4
;LOOP:   DEC R4     
;        MOV A, R4          
;        CJNE A, #0E1h, LOOP 
;        END

;Q5s
;    MOV R6, R0    ; Assume R0 is the largest first
;    MOV A, R1     ; Load R1 to A for comparison
;    CJNE A, R6, NEXT1 ; If A != R6 and A < R6, skip the update
;    MOV R6, A     ; Update R6 with A's value if A > R6
;NEXT1:
;    MOV A, R2     ; Load R2 to A for comparison
;    CJNE A, R6, NEXT2 ; If A != R6 and A < R6, skip the update
;    MOV R6, A     ; Update R6 with A's value if A > R6
;NEXT2:
;    MOV A, R3     ; Load R3 to A for comparison
;    CJNE A, R6, NEXT3 ; If A != R6 and A < R6, skip the update
;    MOV R6, A     ; Update R6 with A's value if A > R6
;NEXT3:
;    MOV A, R4     ; Load R4 to A for comparison
;    CJNE A, R6, DONE ; If A != R6 and A < R6, skip the update
;    MOV R6, A     ; Update R6 with A's value if A > R6
;DONE:
;    END


;Q8	
;	MOV B, #0FFH
;	MOV R0, #00H    ; Initialize the counter to 0
;	MOV A, B         ; Move the value of B into accumulator A for processing
;	MOV R1, #8       ; Initialize a loop counter to 8 for 8 bits
;COUNT_LOOP:
;	RLC A            ; Rotate left through carry. The MSB of A goes into the carry flag.
;	JNC NO_INCREMENT ; If the carry flag is not set (bit was 0), no need to increment R5
;	INC R0           ; If the carry flag is set (bit was 1), increment the count
;NO_INCREMENT:
;    	DJNZ R1, COUNT_LOOP ; Decrement the loop counter and repeat if not 0
;	END


;Q13
;	MOV R4,#0FFh   ;you can store any number u like
;	MOV R5,#0FFh 
;main:
;         DJNZ R4,main        
;         DJNZ R5,end1    ;There is a specific reason for placing it here *
;         DEC R5
;         MOV R4,#0FFh 
;         SJMP main
;end1:    NOP
;	END

;Q17
;    	MOV R0, #00H         ; Initialize R0 with 0
;	ACALL INCREMENT_R0    ; Call the subroutine to increment R0
;	MOV A, SP            ; Get current stack pointer value
;    	ADD A, #-1           ; Adjust stack pointer back by 1 (hypothetical)
;    	MOV SP, A            ; Update stack pointer
; 	SJMP $                ; Infinite loop to stop further execution

;INCREMENT_R0:             ; Subroutine label
;    	INC R0                ; Increment R0 by 1
;    	PUSH ACC            ; Push accumulator onto stack (example)
;    	RET                   ; Return from subroutine
;	END                   ; End of assembly file

;Q19
	MOV DPTR,#100H
	MOV A,#0AAH
	MOV R5,#0FFH
AGAIN:	MOVX @DPTR,A
	INC DPTR
	DEC R5
	CJNE R5,#0FEH,AGAIN
	MOVX @DPTR,A
   	SJMP $
   	END
   	
 



