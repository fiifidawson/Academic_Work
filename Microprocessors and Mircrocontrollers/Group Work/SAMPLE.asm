ORG 000H
AJMP Start
ORG 30H

Start:  
    setb P0.0
    setb P0.1
    setb P0.2
    setb P0.3
    setb P1.0
    JB P1.0, CheckLED ; Jump if switch is pressed
    SJMP Start

CheckLED:
    JB P0.0, Next1
    JB P0.1, Next2
    JB P0.2, Next3
    SETB P0.0 
    SJMP Delay

Next1:
    CLR P0.0 
    SETB P0.1 
    SJMP Delay

Next2:
    CLR P0.1 
    SETB P0.2 
    SJMP Delay

Next3:
    CLR P0.2 
    SETB P0.3 
    SJMP Delay

Next4:
    CLR P0.3 ; Turn off fourth LED
    SJMP Start ; Restart the cycle

Delay: 
    MOV R2, #10h
DelayLoop:
    DJNZ R2, DelayLoop
    SJMP Start
END
