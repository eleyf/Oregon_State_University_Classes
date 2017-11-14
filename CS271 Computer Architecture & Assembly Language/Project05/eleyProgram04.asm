TITLE Composite Numbers	(eleyProgram04.asm)

; Author: Frederick Eley eleyf@oregonstate.edu
; Course / Project ID: CS271-400 Project 4                Date: 2/19/17
; Description: This program will calculate a specified number of composite numbers
;				It will use procedures to
;				display the program title and programmer's name,
;				get and validate the user input,
;				compute and display composite numbers,
;				and display a parting message message.

INCLUDE Irvine32.inc

	LOWER_LIMIT = 1
	UPPER_LIMIT = 400

.data
	intro1			BYTE "Composite Numbers", 0 
	intro2			BYTE "Programmed By Frederick Eley", 0
	instructions1	BYTE "Enter the number of composite numbers you would like to see.", 0
	instructions2	BYTE "I'll accept orders for up to 400 composites.", 0
	validate1		BYTE "Enter the number of composites to display [1 .. 400]: ",0
	validate2		BYTE "Out of range. Try again.",0
	spaces			BYTE "   ",0
	numToDisplay	DWORD ?
	lineCounter		DWORD ?
	currentValue	DWORD ?
	farewell1		BYTE "Results verified by Frederick Eley. Goodbye.", 0


.code
main PROC

	call	introduction
	call	getUserData
	call	showComposites
	call	farewell
		
	exit	; exit to operating system
main ENDP


;Procedure to introduce the program
;receives:	none
;returns:	none
;preconditions:	none
;registers changed:	edx
introduction PROC

	;Display program title and programmer's name
		mov		edx, OFFSET intro1
		call	WriteString
		call	CrLf
		mov		edx, OFFSET intro2
		call	WriteString
		call	CrLf
		call	CrLf

		ret
introduction ENDP


;Procedure to get the total number of values to display from the user
;receives:	none
;returns:	numToDisplay global variable
;preconditions:	none
;registers changed:	edx, eax changed by validate procedure
getUserData	PROC

	;display instructions for data input
		mov		edx, OFFSET instructions1
		call	WriteString
		call	CrLf
		mov		edx, OFFSET instructions2
		call	WriteString
		call	CrLf
		call	CrLf

		call	validate

		mov		numToDisplay, eax

		call	CrLf
		ret
getUserData	ENDP


;Procedure to get and validate the number of values to display
;receives:	none
;returns:	number of values to be calculated in eax
;preconditions:	none
;registers changed:	eax, edx
validate PROC

	;post-test do-while loop to get and verify data
		validationLoop:
			mov		edx, OFFSET validate1
			call	WriteString
			call	ReadInt
			cmp		eax, LOWER_LIMIT
			jl		outOfRange				;if less than lower limit go to outOfRange
			cmp		eax, UPPER_LIMIT
			jg		outOfRange				;if greater than upper limit go to outOfRange
			jmp		endValidationLoop

		;display out of range message and jump back to
		;beginning of validation loop
		
				outOfRange:
					mov		edx, OFFSET validate2
					call	WriteString
					call	CrLf
					jmp		validationLoop

		endValidationLoop:

	ret
validate ENDP


;Procedure to display composite numbers
;receives:	numToDisplay as a global variable
;returns:	none
;preconditions:	numToDisplay must be between lower and upper limits
;registers changed:	eax, ecx, edx
showComposites PROC
	;display composites
		mov		ecx, numToDisplay
		mov		eax, 1
		mov		lineCounter, 0
		mov		currentValue, 4
	
	displayLoop:
		call	WriteDec
		mov		edx, OFFSET spaces
		call	WriteString
		inc		eax
		inc		lineCounter
		cmp		lineCounter, 10
		jl		endLoop
		call	CrLf
		mov		lineCounter, 0

		endLoop:
			loop	displayLoop

		call CrLf
		call CrLf

	ret
showComposites ENDP


;Procedure to test if a number is composite
;recieves:	
;returns:	
;preconditions:	none
;registers changed:	edx
isComposite PROC
	;compute if value is a compsite

	ret
isComposite ENDP


;Procedure to end the program
;receives:	none
;returns:	none
;preconditions:	none
;registers changed:	edx
farewell PROC
	;display parting message
		mov		edx, OFFSET farewell1
		call	WriteString
		call	CrLf
		call	CrLf

		ret
farewell ENDP

END main
