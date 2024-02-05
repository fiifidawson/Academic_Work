	MOV A, #00h  
	CLR P0.0    
	CLR P0.1
	CLR P0.2
	CLR P0.3
	MainLoop:
	JB P1.0, CheckSwitch  
	SJMP MainLoop         

CheckSwitch:
	INC A                 
	ANL A, #03h           
	CJNE A, #00h, NextLED 
	SETB P0.0             
	CLR P0.1
	CLR P0.2
	CLR P0.3
	SJMP MainLoop

NextLED:
	CJNE A, #01h, NextLED2
	CLR P0.0
	SETB P0.1             
	CLR P0.2
	CLR P0.3
	SJMP MainLoop

NextLED2:
	CJNE A, #02h, NextLED3 
	CLR P0.0
	CLR P0.1
	SETB P0.2             
	CLR P0.3
	SJMP MainLoop

NextLED3:
	CLR P0.0
	CLR P0.1
	CLR P0.2
	SETB P0.3            
	SJMP MainLoop
END