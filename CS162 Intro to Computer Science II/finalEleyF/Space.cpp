/*********************************************************************  
** Program Filename:  Space.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Space
**				 class.
**
*********************************************************************/

#include "Space.hpp"

/* setters */
void Space::setPRight(Space & r)
{
	pRight = & r;
}

void Space::setPLeft(Space & l)
{
	pLeft = & l;
}

void Space::setPTop(Space & t)
{
	pTop = & t;
}

void Space::setPBottom(Space & b)
{
	pBottom = & b;
}

void Space::setNameOfSpace(std::string n)
{
	nameOfSpace = n;
}

/* getters */
Space * Space::getPRight() const
{
	return pRight;
}

Space * Space::getPLeft() const
{
	return pLeft;
}

Space * Space::getPTop() const
{
	return pTop;
}

Space * Space::getPBottom() const
{
	return pBottom;
}

std::string Space::getNameOfSpace() const
{
	return nameOfSpace;
}

