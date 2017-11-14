TITLE Sorting Random Numbers	(eleyProgram05.asm)

; Author: Frederick Eley eleyf@oregonstate.edu
; Course / Project ID: CS271-400 Project 5                Date: 3/05/17
; Description: This program will create an array of a specified number of random values.
;				It will use procedures to
;				display the program title and programmer's name,
;				get and validate the user input,
;				fill an array with random numbers,
;				sort the array,
;				display the array,
;				and display the median.

INCLUDE Irvine32.inc

	MIN = 10
	MAX = 200
	LO	= 100
	HI	= 999

.data
	intro1			BYTE "Sorting Random Numbers", 0 
	intro2			BYTE "Programmed By Frederick Eley", 0
	instructions1	BYTE "This program generates random numbers in the range [100 .. 999],", 0
	instructions2	BYTE "displays the original list, sorts the list, and calculates the", 0
	instructions3	BYTE "median value. Finally, it displays the list sorted in descending order.", 0
	validate1		BYTE "How many numbers should be generated? [10 .. 200]: ",0
	validate2		BYTE "Invalid input.",0
	spaces			BYTE "   ",0
	titleUnsorted	BYTE "The unsorted radom numbers:",0
	titleSorted		BYTE "The sorted list:",0
	median1			BYTE "The median is ",0
	request			DWORD ?
	array			DWORD MAX DUP(?)
	lineCounter		DWORD ?



.code
main PROC

	call	Randomize

	call	introduction

	;get user data
	push	OFFSET	request
	call	getUserData

	;fill array
	push	OFFSET	array
	push	request
	call	fillArray

	;display unsorted list
	push	OFFSET	titleUnsorted
	push	OFFSET	array
	push	request
	call	displayList

	;sort list
	push	OFFSET	array
	push	request
	call	sortList

	;display median
	push	OFFSET array
	push	request
	call	displayMedian

	;display sorted list
	push	OFFSET	titleSorted
	push	OFFSET	array
	push	request
	call	displayList
	 
		
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


;*********************************************************************
;Procedure to get the total number of values to display from the user
;receives:	address of request on system stack 
;returns:	user value put into address of request
;preconditions:	none
;registers changed:	ebx, edx...eax changed by validate procedure
;**********************************************************************
getUserData	PROC

	;display instructions for data input
		push	ebp
		mov		ebp,esp 
		mov		edx, OFFSET instructions1
		call	WriteString
		call	CrLf
		mov		edx, OFFSET instructions2
		call	WriteString
		call	CrLf
		call	CrLf

		call	validate

		mov		ebx,[ebp+8]
		mov		[ebx],eax
		pop		ebp
		call	CrLf
		ret		4
getUserData	ENDP


;***************************************************************
;Procedure to get and validate the number of values to display
;receives:	none
;returns:	number of values to be calculated in eax
;preconditions:	none
;registers changed:	eax, edx
;***************************************************************
validate PROC

	;post-test do-while loop to get and verify data
		validationLoop:
			mov		edx, OFFSET validate1
			call	WriteString
			call	ReadInt
			cmp		eax, MIN
			jl		outOfRange				;if less than MIN go to outOfRange
			cmp		eax, MAX
			jg		outOfRange				;if greater than MAX go to outOfRange
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


; ***************************************************************
; Procedure to put random numbers into the array. 
; receives: address of array and value of request on system stack 
; returns: first request elements of array contain random numbers 
; preconditions: request is initialized, MIN <= request <= MAX 
; registers changed: eax, ebx, ecx, edi 
; *************************************************************** 
fillArray PROC

		push	ebp 
		mov		ebp,esp 
		mov		ecx,[ebp+8]		;request in ecx 
		mov		edi,[ebp+12]	;address of array in edi


	fillLoop:		
		;generate random number
			mov		eax, HI
			sub		eax, LO
			inc		eax
			call	RandomRange
			add		eax, LO

		mov		[edi],eax 
		add		edi,4 
		inc		ebx 
		loop	fillLoop

		pop		ebp 
		ret		8

fillArray ENDP


; ***************************************************************
; Procedure to display list
; receives: address of array, address of title and
;			value of request on system stack
; returns: none 
; preconditions: request is initialized, MIN <= request <= MAX 
; registers changed: eax, ecx, edx, esi 
; *************************************************************** 
displayList PROC

		push	ebp 
		mov		ebp,esp 
		mov		ecx,[ebp+8]		;request in ecx 
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
		call	CrLf

		pop		ebp 
		ret		12

displayList ENDP


; ***************************************************************
; Procedure to sort list
; receives: address of array and value of request on system stack
; returns: elements of array sorted in descending oreder 
; preconditions: request is initialized, MIN <= request <= MAX 
; registers changed: eax, ecx, esi 
; ***************************************************************
sortList PROC

		push	ebp 
		mov		ebp,esp 
		mov		ecx,[ebp+8]		;request in ecx
		dec		ecx

	outerLoop:
		push	ecx
		mov		esi,[ebp+12]	;address of array in esi

	innerLoop:
		mov		eax,[esi]
		cmp		[esi+4],eax
		jl		endInnerLoop
		xchg	eax,[esi+4]
		mov		[esi],eax

	endInnerLoop:
		add		esi,4
		loop	innerLoop

		pop		ecx
		loop	outerLoop

	endOuterLoop:

		pop		ebp 
		ret		8

sortList ENDP


; ***************************************************************
; Procedure to display median
; receives: address of array and value of request on system stack
; returns: none
; preconditions: request is initialized, MIN <= request <= MAX, 
;				 list is sorted
; registers changed: eax, ebx, edx, esi 
; ***************************************************************
displayMedian PROC

		push	ebp 
		mov		ebp,esp 
		mov		eax,[ebp+8]		;request in eax
		mov		edx, 0
		mov		ebx, 2
		div		ebx				
		mov		ebx, 4
		mul		ebx				;multiple by 4 because DWORD
								;median position is in eax

		mov		esi,[ebp+12]	;address of array in esi
		add		esi, eax
		mov		eax, [esi]

		mov		edx, OFFSET median1
		call	WriteString
		call	WriteDec

		call	CrLf
		call	CrLf

		pop		ebp 
		ret		8

displayMedian ENDP



END main
