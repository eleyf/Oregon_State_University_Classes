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
** Description: Function that takes an Creature pointer as a parameter and
**				adds it to the top of a stack.
**  
*********************************************************************/
void Stack::push(Creature *f)
{
	StackNode *temp;
    temp= new StackNode;
    temp->fighter = f;
    temp->next = top;
    top = temp;
}

/*********************************************************************  
** Function:  pop()
** Description: Function that removes an Creature pointer from the top of a
**				stack and returns its value.
**  
*********************************************************************/
Creature * Stack::pop()
{
	Creature * fighterRemoved;
	
	if (top == NULL)
	{
		return 0;
	}
	else
	{
		StackNode *temp;
		temp = top;
		top = top->next;
		fighterRemoved = temp->fighter;
        delete temp;
        return fighterRemoved;
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
    	std::cout << (temp->fighter)->getTypeOfCreature() << " ";
    	temp = temp->next;
    }

    std::cout << std::endl;
}


