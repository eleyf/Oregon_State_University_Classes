TITLE Fibonacci Numbers     (eleyProgram02.asm)

; Author: Frederick Eley eleyf@oregonstate.edu
; Course / Project ID: CS271-400 Project 2                Date: 1/29/17
; Description: This program will calculate Fibonacci numbers.
;				It will
;				display the program title and programmer's name,
;				prompt the user to enter the number of Fibonacci terms to be displayed,
;				get and validate the user input,
;				calculate and display the Fibonacci numbers,
;				and display a parting message message.

INCLUDE Irvine32.inc

	LOWER_LIMIT = 1
	UPPER_LIMIT = 46

.data
	intro1			BYTE "Fibonacci Numbers", 0 
	intro2			BYTE "Programmed By Frederick Eley", 0
	instructions1	BYTE "What's your name? ", 0
	userName		BYTE 33 dup(0)
	instructions2	BYTE "Hello, ", 0
	instructions3	BYTE "Enter the number of Fibonacci terms to be displayed.", 0
	instructions4	BYTE "Give the number as an integer in the range [1..46]", 0
	dataPrompt1		BYTE "How many Fibonacci terms do you want? ",0
	dataPrompt2		BYTE "Out of range. Enter a number in the range [1..46]",0
	numToCalc		DWORD ?
	currentFib		DWORD ?
	previousFib		DWORD ?
	tempFib			DWORD ?
	displaySpaces	BYTE "     ",0
	farewell1		BYTE "Results certified by Frederick Eley.", 0
	farewell2		BYTE "Goodbye, ", 0


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

;userInstructions
		mov edx, OFFSET instructions1
		call WriteString
		mov edx, OFFSET userName
		mov ecx, 32
		call ReadString
		mov edx, OFFSET instructions2
		call WriteString
		mov edx, OFFSET userName
		call WriteString
		call CrLf
		mov edx, OFFSET instructions3
		call WriteString
		call CrLf
		mov edx, OFFSET instructions4
		call WriteString
		call CrLf
		call CrLf

;getUserData
	;post-test do-while loop to get and verify data is in range
		validationLoop:
			mov edx, OFFSET dataPrompt1
			call WriteString
			call ReadInt
			cmp eax, LOWER_LIMIT
			jl	outOfRange
			cmp eax, UPPER_LIMIT
			jg	outOfRange
			jmp endValidationLoop

			;display out of range message and jump back to
			;beginning of validation loop
			outOfRange:
				mov edx, OFFSET dataPrompt2
				call WriteString
				call CrLf
				jmp validationLoop

		endValidationLoop:
			mov numToCalc, eax
			call CrLf
			
;displayFibs
	;initialize values to calculate Fibonacci numbers
		mov previousFib, 0
		mov	currentFib, 1
		mov ecx, numToCalc
		mov edx, OFFSET displaySpaces

	;for loop to calculate and display Fibonacci numbers
		fibLoop:
			mov eax, currentFib
			call WriteDec
			call WriteString
			mov tempFib, eax
			add	eax, previousFib
			mov currentFib, eax
			mov ebx, tempFib
			mov previousFib, ebx
			loop fibLoop

	call CrLf
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
