/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/
int isBalanced(char* s)
{
	/* FIXME: You will write this function */

    assert(s != NULL);

    DynArr *bracketStack;
    bracketStack = newDynArr(5);
    char currentCharacter;

    currentCharacter = nextChar(s);
    while (currentCharacter != '\0') {
        if (currentCharacter == '(' || currentCharacter == '{' || currentCharacter == '[') {
            switch(currentCharacter){

                case '(':
                    pushDynArr(bracketStack, ')');
                    break;

                case '{':
                    pushDynArr(bracketStack, '}');
                    break;

                case '[':
                    pushDynArr(bracketStack, ']');
                    break;
            }

        } else if (currentCharacter == ')' || currentCharacter == '}' || currentCharacter == ']') {

            if (isEmptyDynArr(bracketStack)) {
                deleteDynArr(bracketStack);
                return 0;
            } else if (!EQ(currentCharacter, topDynArr(bracketStack))) {
                deleteDynArr(bracketStack);
                return 0;
            } else {
                popDynArr(bracketStack);
            }
        }
        //Read next character
        currentCharacter = nextChar(s);
    }

    //If the stack is empty after reading all characters the expression is balanced
    if (isEmptyDynArr(bracketStack)) {
        deleteDynArr(bracketStack);
        return 1;
    } else {
        deleteDynArr(bracketStack);
        return 0;
    }
}

int main(int argc, char* argv[]){
	
	char* s=argv[1];

	int res;
	
	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n",s);
	else 
		printf("The string %s is not balanced\n",s);
	
	return 0;	
}

