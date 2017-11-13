/*********************************************************************  
** Program Filename:  Stack.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Stack Class Header. 
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include "Creature.hpp"


class Stack
{
protected:
	struct 	StackNode
	{
		Creature	*fighter;
		StackNode 	*next;
	};

	StackNode *top;
	

public:
	Stack();
	~Stack();
    void 		push(Creature *f);
    Creature *	pop();
    void 		displayStack() const;
};

#endif