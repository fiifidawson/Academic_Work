; Water dispenser
TRIG EQU P1.5   ; Define trigger pin
ECHO EQU P1.4   ; Define echo pin
RELAY EQU P1.6  ; Define relay pin

DSEG AT 30H     ; Data segment
TIME  DS 2      ; Store time value
DIST  DS 2      ; Store distance value

CSEG            ; Code segment
; Initialization
INIT:
    MOV SP, #60H   ; Initialize stack pointer
    MOV TMOD, #01H ; Set Timer 0 in mode 1 (16-bit timer)
    SETB TRIG       ; Set trigger pin high
    CLR TRIG        ; Clear trigger pin low
    SETB EA         ; Enable global interrupts

; Main loop
MAIN:
    CALL MEASURE    ; Measure distance
    MOV A, DIST     ; Load distance value
    CJNE A, #05H, HIGH ; If distance >= 5, go to HIGH
    CLR RELAY       ; Clear relay pin (turn relay off)
    SJMP MAIN       ; Loop back to MAIN

HIGH:
    SETB RELAY      ; Set relay pin (turn relay on)
    SJMP MAIN       ; Loop back to MAIN

; Measure distance
MEASURE:
    CLR TR0         ; Stop Timer 0
    MOV TH0, #0     ; Clear Timer 0 high byte
    MOV TL0, #0     ; Clear Timer 0 low byte
    SETB TRIG       ; Set trigger pin high
    NOP             ; Short delay
    CLR TRIG        ; Clear trigger pin low
    JNB ECHO, $     ; Wait for echo pin to go high
    SETB TR0        ; Start Timer 0
    JNB ECHO, $     ; Wait for echo pin to go low
    CLR TR0         ; Stop Timer 0
    MOV TIME, TL0   ; Store time value in low byte
    MOV TIME+1, TH0 ; Store time value in high byte
    MOV A, TIME     ; Load time value
    MOV B, #58      ; Load divisor (58 = 1/0.034 * 2)
    DIV AB          ; Divide time by 58 (distance in cm)
    MOV DIST, A     ; Store distance value
    RET             ; Return from subroutine
END