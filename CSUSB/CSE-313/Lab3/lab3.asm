;Class: CSE 313 Machine Organization Lab
;Section: 04
;Instructor: Thakshak Gudimetla
;Term: Spring 2017
;Name(s): Adnar Lozano Leon
;Lab#3: Days of the Week
	.ORIG X3000
RESTART LEA R0, PROMPT
	PUTS
	GETC
	ADD R3,R0,x0
	ADD R3,R3,#-16
	ADD R3,R3,#-16
 	ADD R3,R3,#-16
	ADD R4,R3,#-6
	BRp ERROR
	LEA R0, DAYS
	ADD R3, R3, x0      
LOOP	BRz DISPLAY
	ADD R0, R0, #10
	ADD R3, R3, #-1
	BR LOOP		   
DISPLAY	PUTS
	LEA R0, LF	
	PUTS
	BR RESTART
ERROR HALT
PROMPT	.STRINGZ "PLEASE ENTER NUMBER: "
DAYS	.STRINGZ "Sunday   "		    
	.STRINGZ "Monday   "
	.STRINGZ "Tuesday  "
	.STRINGZ "Wednesday"
	.STRINGZ "Thursday "
	.STRINGZ "Friday   "
	.STRINGZ "Saturday "
	.STRINGZ "INVALID INPUT"
LF	.FILL x000A
	.END