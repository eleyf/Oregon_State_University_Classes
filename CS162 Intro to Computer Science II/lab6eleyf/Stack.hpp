/*********************************************************************  
** Program Filename:  Stack.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Stack Class Header. 
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream> 


class Stack
{
protected:
	struct 	StackNode
	{
		int	num;
		StackNode 	*next;
	};

	StackNode *top;
	

public:
	Stack();
	~Stack();
    void 	push(int n);
    int		pop();
    void 	displayStack() const;
};

#endif