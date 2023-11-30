; Assuming the value is already in the accumulator (register A)
    
    MOV  A, #47h
    MOV  B, A          ; Copy accumulator to B register for comparison
    ANL  A, #F0h       ; Mask the upper nibble
    SWAP A             ; Swap nibbles in A, moving the upper nibble to the lower position
    MOV  C, A          ; Copy the original upper nibble (now lower) to the carry
    CLR  A             ; Clear the accumulator
    ANL  A, B          ; Isolate the original lower nibble
    SUBB A, C          ; Subtract the original upper nibble from lower nibble
    JC   SET_CARRY     ; If borrow occurs, the upper nibble was larger, jump to set carry
    CLR  C             ; Otherwise, clear the carry
    ;SJMP END           ; Skip the set carry instruction

SET_CARRY:
    SETB C             ; Set the carry flag

END
    ; Rest of the program
