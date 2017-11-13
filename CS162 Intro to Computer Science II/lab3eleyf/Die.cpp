/*********************************************************************  
** Program Filename:  Die.cpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  These are the function definitions of the Die
**				 class.
** Input:	The default constructor creates a 6 sided die.
**
**			Another constructor creates a die of of the specified
**			size.
**
*********************************************************************/

#include "Die.hpp"


/* constructors */
Die::Die()
{
	setSides(6);
}


Die::Die(int sides)
{
	setSides(sides);
}


/* setters and getters */
void Die::setSides(int sides)
{
	this->sides = sides;
}

int Die::getSides() const
{
	return sides;
}


/*********************************************************************  
** Function:  roll()
** Description: Function that simulates the roll of a die of a
**				given number of sides.
**
**  
*********************************************************************/
int Die::roll() const
{
	return getRandom(1, sides);
}









