TITLE Designing low-level I/O procedures	(eleyProgram06.asm)

; Author: Frederick Eley eleyf@oregonstate.edu
; Course / Project ID: CS271-400 Project 6               Date: 3/19/17
; Description: This program will create an array of a specified number of user input values.
;				It will use macros and procedures to
;				display the program title and programmer's name,
;				get and validate the user string input and convert it to a numeric value,
;				fill an array with the input numbers,
;				display the array,
;				display the sum of the array elements
;				and display the average of the array elements.

INCLUDE Irvine32.inc

getString	MACRO readPrompt, readBuffer, readCount
	push		edx
	push		ecx
	mov			edx, readPrompt
	call		WriteString
	mov			edx, readBuffer
	mov			ecx, MAXSIZE
	call		ReadString
	mov			readCount, eax
	pop			ecx
	pop			edx

ENDM

displayString	MACRO displayBuffer
	push		edx
	mov			edx, displayBuffer
	call		WriteString
	call		CrLf
	pop			edx

ENDM

	MAXSIZE	= 100
	MAXARR	= 10

.data
	intro1			BYTE "PROGRAMMING ASSIGNMENT 6: Designing low-level I/O procedures", 0 
	intro2			BYTE "Programmed By Frederick Eley", 0
	instructions1	BYTE "Please provide 10 unsigned decimal integers.", 0
	instructions2	BYTE "Each number needs to be small enough to fit inside a 32 bit register.", 0
	instructions3	BYTE "After you have finished inputting the raw numbers I will display a list", 0
	instructions4	BYTE "of the integers, their sum, and their average value.", 0
	validate1		BYTE "Please enter an unsigned number: ",0
	validate2		BYTE "ERROR: You did not enter an unsigned number or your number was too big.",0
	validate3		BYTE "Please try again: ",0
	spaces			BYTE "   ",0
	listPrompt		BYTE "You entered the following numbers:",0
	sumPrompt		BYTE "The sum of these numbers is: ",0
	averagePrompt	BYTE "The average is: ",0
	inString		BYTE	MAXSIZE DUP(?)
	outString		BYTE	MAXSIZE DUP(?)
	numericVal		DWORD ?
	stringLength	DWORD ?
	arraySum		DWORD ?
	array			DWORD MAXARR DUP(?)
	lineCounter		DWORD ?



.code
main PROC

		call	introduction
		call	instructions

	;fill array
		push	OFFSET	array
		push	MAXARR
		call	fillArray

	;display list
		push	OFFSET	listPrompt
		push	OFFSET	array
		push	MAXARR
		call	displayList

	;calculate sum
		push	OFFSET	array
		push	MAXARR
		call	calculateSum

	;display sum
		push	arraySum
		push	OFFSET	sumPrompt
		call	displaySum

	;display average
		push	arraySum
		push	OFFSET	averagePrompt
		push	MAXARR
		call	displayAverage
		
	exit	; exit to operating system
main ENDP


;************************************
;Procedure to introduce the program
;receives:	none
;returns:	none
;preconditions:	none
;registers changed:	edx
;************************************
introduction PROC

		push	edx

	;Display program title and programmer's name
		mov		edx, OFFSET intro1
		call	WriteString
		call	CrLf
		mov		edx, OFFSET intro2
		call	WriteString
		call	CrLf
		call	CrLf

		pop		edx
		ret
introduction ENDP


;************************************
;Procedure to display instructions
;receives:	none
;returns:	none
;preconditions:	none
;registers changed:	edx
;************************************
instructions PROC

		push	edx

	;Display program instructions
		mov		edx, OFFSET instructions1
		call	WriteString
		call	CrLf
		mov		edx, OFFSET instructions2
		call	WriteString
		call	CrLf
		mov		edx, OFFSET instructions3
		call	WriteString
		call	CrLf
		mov		edx, OFFSET instructions4
		call	WriteString
		call	CrLf
		call	CrLf

		pop		edx
		ret
instructions ENDP


; ***************************************************************
; Procedure to readVal. 
; receives: address of string on system stack 
; returns: numericVal converted to integer from string input 
; preconditions: none
; registers changed: eax, ebx, ecx, edx, esi 
; *************************************************************** 
readVal PROC

		push	ebp 
		mov		ebp,esp

		push	eax
		push	ebx
		push	ecx
		push	edx
		push	esi

	;getString      OFFSET validate1, OFFSET inString, stringLength
	getString		[ebp+8], [ebp+20], [ebp+24]	
	readLoop:
		mov				ecx, [ebp+24]
		cmp				ecx, 10				;more than 10 char too big
		jg				notNum
		mov				edx, 0				;numericVal during calculation
		mov				esi, [ebp+20]		;OFFSET inString to esi
		cld

		convertLoop:
			lodsb

			;test if character is a digit
				cmp		al, 48		;'0' is character 48
				jb		notNum
				cmp		al, 57		;'9' is character 57
				ja		notNum

			;convert character to number
				imul	edx, 10
				sub		al, 48
				movzx	ebx, al
				add		edx, ebx
				loop convertLoop
			
				jmp endReadLoop
 
			notNum:
				mov		edx, [ebp+12]	;OFFSET validate2
				call	WriteString
				call	CrLf
				;getString      OFFSET validate3, OFFSET inString, stringLength
				getString		[ebp+16], [ebp+20], [ebp+24] 
				jmp		readLoop
	endReadLoop:

	mov		numericVal, edx			;edx into numericVal
		
	pop		esi
	pop		edx
	pop		ecx
	pop		ebx
	pop		eax
	pop		ebp 
	ret		20

readVal ENDP


; ***************************************************************
; Procedure to put numbers into the array. 
; receives: address of array and size of array on system stack 
; returns: array filled with user values
; preconditions: none
; registers changed: eax, ebx, ecx, edi 
; *************************************************************** 
fillArray PROC

		push	ebp 
		mov		ebp,esp
		
		push	eax
		push	ebx
		push	ecx
		push	edi
		 
		mov		ecx,[ebp+8]		;MAXARR in ecx 
		mov		edi,[ebp+12]	;address of array in edi


	fillLoop:
	
		;get number from user
			push	stringLength
			push	OFFSET	inString
			push	OFFSET	validate3
			push	OFFSET	validate2
			push	OFFSET	validate1
			call	readVal		

		mov		eax, numericVal
		mov		[edi],eax
		add		edi,4 
		inc		ebx 
		loop	fillLoop

		call	CrLf
		pop		edi
		pop		ecx
		pop		ebx
		pop		eax
		pop		ebp 
		ret		8

fillArray ENDP


; ***************************************************************
; Procedure to display list
; receives: address of array, address of title and
;			value of MAXARR on system stack
; returns: none 
; preconditions: MAXARR elements in array
; registers changed: eax, ecx, edx, esi 
; *************************************************************** 
displayList PROC

		push	ebp 
		mov		ebp,esp 

		push	eax
		push	ecx
		push	edx
		push	esi

		mov		ecx,[ebp+8]		;MAXARR in ecx 
		mov		esi,[ebp+12]	;address of array in esi
		mov		lineCounter, 0

		mov		edx, [ebp+16]	;address of title in edx
		call	WriteString
		call	CrLf


	displayLoop:
		mov		eax,[esi]
		call	WriteDec
		mov		edx, OFFSET spaces
		call	WriteString
		add		esi,4
		inc		lineCounter
		cmp		lineCounter, 10
		jl		endLoop
		call	CrLf
		mov		lineCounter, 0

		endLoop:
			loop	displayLoop

		call	CrLf

		pop		esi
		pop		edx
		pop		ecx
		pop		eax
		pop		ebp 
		ret		12

displayList ENDP


; ***************************************************************
; Procedure to calculate sum of array elements
; receives: address of array and value of MAXARR on system stack
; returns: sum of elements in arraySum
; preconditions: MAXARR elements in array 
; registers changed: eax, ecx, edi 
; ***************************************************************
calculateSum PROC

		push	ebp 
		mov		ebp,esp

		push	eax
		push	ecx
		push	edi
		
		mov		ecx,[ebp+8]			;MAXARR in ecx 
		mov		edi,[ebp+12]		;address of array in edi
		mov		eax, 0				;eax is sum while calculating
		
	sumLoop:
		add		eax, [edi]
		add		edi, TYPE array
		loop	sumLoop

		mov		arraySum,eax		;eax in arraySum

		pop		edi
		pop		ecx
		pop		eax
		pop		ebp 
		ret		8

calculateSum ENDP


; ************************************************************************
; Procedure to display sum
; receives: address of sumPrompt and value of arraySum on system stack
; returns: none
; preconditions: arraySum has been calculated			 
; registers changed: eax, edx 
; *************************************************************************
displaySum PROC

		push	ebp 
		mov		ebp,esp

		push	eax
		push	edx

		mov		edx,[ebp+8]			;address of sumPrompt in edx
		call	WriteString
		mov		eax, [ebp+12]		;arraySum in eax
		call	WriteDec
		call	CrLf


		pop		edx
		pop		eax
		pop		ebp 
		ret		8

displaySum ENDP


; ************************************************************************
; Procedure to display average
; receives: address of averagePrompt, the value of arraySum, and value of
;			MAXARR on system stack
; returns: none
; preconditions: arraySum calculated, array has MAXARR elements
; registers changed: eax, ebx, edx 
; *************************************************************************
displayAverage PROC

		push	ebp 
		mov		ebp,esp

		push	eax
		push	ebx
		push	edx

		mov		edx,[ebp+12]		;address of averagePrompt in edx
		call	WriteString

		;calculate average
		mov		edx,0
		mov		eax, [ebp+16]		;arraySum in eax
		mov		ebx, [ebp+8]		;MAXARR in ebx
		div		ebx
		
		call	WriteDec
		call	CrLf


		pop		edx
		pop		ebx
		pop		eax
		pop		ebp 
		ret		12

displayAverage ENDP


END main
