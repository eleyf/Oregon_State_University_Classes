/*********************************************************************  
** Program Filename:  Stack.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  These are the function definitions of the Stack
**				 class.
**
**
*********************************************************************/

#include "Stack.hpp"


/* constructor */
Stack::Stack()
{
	top = NULL;
}


/* destructor */
Stack::~Stack()
{
	while(top != NULL)
	{
    	StackNode *temp;
    	temp = top;
    	top = top->next;
    	delete temp;
    }
}

/*********************************************************************  
** Function:  push()
** Description: Function that takes an interger as a parameter and
**				adds it to the top of a stack.
**  
*********************************************************************/
void Stack::push(int n)
{
	StackNode *temp;
    temp= new StackNode;
    temp->num = n;
    temp->next = top;
    top = temp;
}

/*********************************************************************  
** Function:  pop()
** Description: Function that removes an interger from the top of a
**				stack and returns its value.
**  
*********************************************************************/
int Stack::pop()
{
	int numRemoved;
	
	if (top == NULL)
	{
		std::cout << "The stack is empty, there is nothing to remove." << std::endl;
		return 0;
	}
	else
	{
		StackNode *temp;
		temp = top;
		top = top->next;
		numRemoved = temp->num;
        delete temp;
        return numRemoved;
	}
	
}


/*********************************************************************  
** Function:  displayStack()
** Description: Function that displays the contents of the stack.
**
**  
*********************************************************************/
void Stack::displayStack() const
{
	StackNode *temp;

	temp = top;

    while(temp != NULL)
    {
    	std::cout << temp->num << " ";
    	temp = temp->next;
    }

    std::cout << std::endl;
}


