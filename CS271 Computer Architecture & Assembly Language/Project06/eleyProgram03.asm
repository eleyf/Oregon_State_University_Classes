TITLE Integer Accumulator	(eleyProgram03.asm)

; Author: Frederick Eley eleyf@oregonstate.edu
; Course / Project ID: CS271-400 Project 3                Date: 2/12/17
; Description: This program will accumulate the values of negative integers
;				and calculate the average value.
;				It will
;				display the program title and programmer's name,
;				get the user's name and greet the user,
;				display instructions for the user,
;				repeatedly prompt the user to enter a number,
;				validate the user input,
;				count and accumulate the users numbers until a non-negative number is entered,
;				calculate the average of the negative integers,
;				and display the number of negative integers entered,
;				the sum of negative integers entered,
;				the average, rounded to the nearest integer,
;				and a parting message message.

INCLUDE Irvine32.inc

	LOWER_LIMIT = -100
	UPPER_LIMIT = -1

.data
	intro1			BYTE "Welcome to the Integer Accumulator", 0 
	intro2			BYTE "Programmed By Frederick Eley", 0
	greeting1		BYTE "What's your name? ", 0
	userName		BYTE 33 dup(0)
	greeting2		BYTE "Hello, ", 0
	instructions1	BYTE "Enter numbers in the range of [-100, -1]", 0
	instructions2	BYTE "Enter a non-negative number when you are finished to see the results.", 0
	dataPrompt1		BYTE "Enter number: ",0
	dataPrompt2		BYTE "Out of range. Enter a number in the range [-100..-1]",0
	intCounter		DWORD ?
	sum				SDWORD ?
	average			SDWORD ?
	displayPrompt1	BYTE "You entered ",0
	displayPrompt2	BYTE " valid numbers. ",0
	displayPrompt3	BYTE "The sum of your valid numbers is ",0
	displayPrompt4	BYTE "The rounded average is ",0
	displayPrompt5	BYTE "No valid numbers were entered. No calculations done.",0
	farewell1		BYTE "Thank you for playing Integer Accumulator!", 0
	farewell2		BYTE "It's been a pleasure to meet you, ", 0


.code
main PROC

; Introduction
	;Display program title and programmer's name
		mov edx, OFFSET intro1
		call WriteString
		call CrLf
		mov edx, OFFSET intro2
		call WriteString
		call CrLf
		call CrLf


;Greet User
	;get user's name and say hello
		mov edx, OFFSET greeting1
		call WriteString
		mov edx, OFFSET userName
		mov ecx, 32
		call ReadString
		mov edx, OFFSET greeting2
		call WriteString
		mov edx, OFFSET userName
		call WriteString
		call CrLf
		call CrLf


;userInstructions
		mov edx, OFFSET instructions1
		call WriteString
		call CrLf
		mov edx, OFFSET instructions2
		call WriteString
		call CrLf


;getUserData
	;post-test do-while loop to get and verify data,
	;count the number of valid entries, and accumulate the total sum
		mov intCounter, 0
		mov sum, 0 
		accumulatorLoop:
			mov edx, OFFSET dataPrompt1
			call WriteString
			call ReadInt
			cmp eax, LOWER_LIMIT
			jl	outOfRange			;if less than lower limit go to outOfRange
			cmp eax, UPPER_LIMIT
			jg	endAccumulatorLoop	;if greater than upper limit go to endOfAccumulator
			add sum, eax
			inc intCounter
			jmp accumulatorLoop

			;display out of range message and jump back to
			;beginning of accumulator loop
			outOfRange:
				mov edx, OFFSET dataPrompt2
				call WriteString
				call CrLf
				jmp accumulatorLoop

		endAccumulatorLoop:
		call CrLf

;calculateAverage
	;test to see if the divisor is zero
		cmp intCounter, 0
		je zeroDivisor

	;perform division
		mov eax, sum
		cdq
		mov ebx, intCounter
		idiv ebx
		mov average, eax
		jmp endAverage

	zeroDivisor:
		mov average, 0

	endAverage:
	
			
;displayResults
	;test to see if any numbers were entered
		cmp intCounter, 0
		je noValuesEntered

	;display number of valid numbers entered
		mov edx, OFFSET displayPrompt1
		call WriteString
		mov eax, intCounter
		call WriteDec
		mov edx, OFFSET displayPrompt2
		call WriteString
		call CrLf

	;display sum of valid numbers entered
		mov edx, OFFSET displayPrompt3
		call WriteString
		mov eax, sum
		call WriteInt
		call CrLf

	;display the average
		mov edx, OFFSET displayPrompt4
		call WriteString
		mov eax, average
		call WriteInt
		call CrLf
		call CrLf

	jmp endDisplayResults

	;no values entered message
		noValuesEntered:
			mov edx, OFFSET displayPrompt5
			call WriteString
			call CrLf

	endDisplayResults:
			call CrLf
		
;farewell
	;display parting message
		mov edx, OFFSET farewell1
		call WriteString
		call CrLf
		mov edx, OFFSET farewell2
		call WriteString
		mov edx, OFFSET userName
		call WriteString
		call CrLf
		call CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
