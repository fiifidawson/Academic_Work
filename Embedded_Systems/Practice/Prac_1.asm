;Q 3
;MOV 17h,#0H
;MOV 18h,#0H
;MOV A,17h
;ADD A,#84h
;MOV 17h,A
;CLR A
;MOV A,18H
;ADD A,#84h
;MOV 18h,A
;END

;Q 9
;CLR A 
;MOV A, #0F3h
;SUBB A,R2
;MOV DPTR,#028BH 
;MOVX @DPTR,A 
;END

;Q 11
;MOV 2BH, #34H
;MOV 13H, #02H
;MOV A, 2BH
;SUBB A, 13H
;MOV 3CH, A
;END

;Q 13
;MOV R0, #13h 
;INC @R0      
;MOV R0, #14h 
;INC @R0      
;MOV R0, #15h 
;INC @R0 
;END

;Q 15
;MOV DPTR, #0100h 
;MOVX A, @DPTR          
;INC A                  
;MOVX @DPTR, A
;MOV DPTR, #0200h       
;MOVX A, @DPTR         
;INC A              
;MOVX @DPTR, A
;END

;Q 17
;    MOV DPTR, #0100h           
;    MOV R1, #06              

;LOOP_INCREMENT:
;    MOVX A, @DPTR       
;    INC A        
;    MOVX @DPTR, A            
;    INC DPTR                  
;    DJNZ R1, LOOP_INCREMENT
;    END


; Question 18
;DEC TL0
;DEC TH0
;DEC TL1
;DEC TH1
;END

; Question 21
;MOV 15H, #23H
;MOV 22H, #43H
;MOV A,15H ; copy 15H content to A
;MOV B,22H ; copy 22H content to B
;MUL AB ; multiply A with B
;MOV 19h,A ; copy LSB of result to address 19h
;MOV 1Ah,B ; copy MSB of result to 1Ah
;END