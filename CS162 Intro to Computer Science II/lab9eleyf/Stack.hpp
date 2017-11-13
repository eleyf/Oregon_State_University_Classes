/*********************************************************************  
** Program Filename:  Stack.hpp
** Author:  Frederick Eley
** Date:  11/27/16
** Description:  Stack Class Header. 
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <string>
#include <stack>


class Stack
{
private:
	std::stack<char> holdStack;
	std::string word;

public:
	Stack();
	~Stack();
    std::string pal(const std::string & s);
};

#endif