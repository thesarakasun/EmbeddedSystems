;
; blinkerAsm.asm
;
; Created: 8/14/2025 11:25:28 AM
; Author : Thesara
;


; blinkerAsm.asm


   		SBI DDRB, 0      
START: 	SBI PORTB, 0       
   		CALL DELAY       
        CBI PORTB, 0      
    	CALL DELAY        
    	JMP START        

DELAY:	LDI R16, 11        
LOOP1:	LDI R17, 255   
LOOP2:	LDI R18, 255  
LOOP3:	DEC R18        
		BRNE LOOP3         
		DEC R17           
		BRNE LOOP2       
		DEC R16           
		BRNE LOOP1        
		RET