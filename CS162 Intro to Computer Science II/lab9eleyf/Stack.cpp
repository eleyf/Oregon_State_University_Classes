/*********************************************************************  
** Program Filename:  Stack.cpp
** Author:  Frederick Eley  
** Date:  11/27/16
** Description:  These are the function definitions of the Stack
**				 class.
**
**
*********************************************************************/

#include "Stack.hpp"


/* constructor */
Stack::Stack()
{

}


/* destructor */
Stack::~Stack()
{

}

/*********************************************************************  
** Function:  pal()
** Description: Function that takes a string as a parameter and
**				returns it's palindrome as a string.
**  
*********************************************************************/
std::string Stack::pal(const std::string & s)
{
	word = s;

	// add each character of word to stack
	for(int i = 0; i < word.length(); i++)
	{
		holdStack.push(word.at(i));
	}

	// add each character to end of word
	while(! holdStack.empty())
	{
		word = word + holdStack.top();
		holdStack.pop();
	}

	return word;
}


