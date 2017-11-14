TITLE Elementary Arithmetic     (eleyProgram01.asm)

; Author: Frederick Eley eleyf@oregonstate.edu
; Course / Project ID: CS271-400 Project 1                Date: 1/22/17
; Description: This program will 
;				display my name and program title on the output screen,
;				display instructions for the user,
;				prompt the user to enter two numbers,
;				calculate the sum, difference, product, quotient, and remainder of the numbers,
;				and display a terminating message.

INCLUDE Irvine32.inc

; (insert constant definitions here)

.data
	intro1			BYTE "              Elementary Arithmetic         by Frederick Eley", 0 
	intro2			BYTE "Enter 2 numbers and I'll show you the sum, difference, product, quotient, and remainder.", 0
	prompt1			BYTE "First number: ", 0
	prompt2			BYTE "Second number: ", 0
	firstNumber		DWORD ?
	secondNumber	DWORD ?
	sum				DWORD ?
	difference		DWORD ?
	product			DWORD ?
	quotient		DWORD ?
	remainder		DWORD ?
	promptSum		BYTE " + ", 0
	promptDiff		BYTE " - ", 0
	promptMul		BYTE " x ", 0
	promptDiv		BYTE " ",246," ", 0
	promptEqual		BYTE " = ", 0
	promptRemainder BYTE " remainder ", 0
	goodbye			BYTE "Impressed?  Bye!", 0


.code
main PROC

; Introduction
	;Display name and program title
		mov edx, OFFSET intro1
		call WriteString
		call CrLf
		call CrLf

	;Display instructions
		mov edx, OFFSET intro2
		call WriteString
		call CrLf
		call CrLf


; Get the data
	mov edx, OFFSET prompt1
	call WriteString
	call ReadInt
	mov firstNumber, eax

	mov edx, OFFSET prompt2
	call WriteString
	call ReadInt
	mov secondNumber, eax
	call CrLf


; Calculate the required values
	;Calculate sum
		mov eax, firstNumber
		add eax, secondNumber
		mov sum, eax

	;Calculate difference
		mov eax, firstNumber
		sub eax, secondNumber
		mov difference, eax
	
	;Calculate product
		mov eax, firstNumber
		mul secondNumber
		mov product, eax

	;Calculate quotient and remainder
		mov edx, 0
		mov eax, firstNumber
		div secondNumber
		mov quotient, eax
		mov remainder, edx


; Display the results
	;Display sum
		mov eax, firstNumber
		call WriteDec
		mov edx, OFFSET promptSum
		call WriteString
		mov eax, secondNumber
		call WriteDec
		mov edx, OFFSET promptEqual
		call WriteString
		mov eax, sum
		call WriteDec
		call CrLf

	;Display difference
		mov eax, firstNumber
		call WriteDec
		mov edx, OFFSET promptDiff
		call WriteString
		mov eax, secondNumber
		call WriteDec
		mov edx, OFFSET promptEqual
		call WriteString
		mov eax, difference
		call WriteDec
		call CrLf

	;Display product
		mov eax, firstNumber
		call WriteDec
		mov edx, OFFSET promptMul
		call WriteString
		mov eax, secondNumber
		call WriteDec
		mov edx, OFFSET promptEqual
		call WriteString
		mov eax, product
		call WriteDec
		call CrLf

	;Display quotient and remainder
		mov eax, firstNumber
		call WriteDec
		mov edx, OFFSET promptDiv
		call WriteString
		mov eax, secondNumber
		call WriteDec
		mov edx, OFFSET promptEqual
		call WriteString
		mov eax, quotient
		call WriteDec
		mov edx, OFFSET promptRemainder
		call WriteString
		mov eax, remainder
		call WriteDec
		call CrLf
		call CrLf

; Say goodbye
	mov edx, OFFSET goodbye
	call WriteString
	call CrLf
	call CrLf

	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main
