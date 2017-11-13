/*********************************************************************  
** Program Filename:  LoadedDie.cpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  These are the function definitions of the LoadedDie
**				 class.
** Input:	The default constructor creates a 6 sided loaded die.
**
**			Another constructor creates a loaded die of of the 
**			specified size.
**
*********************************************************************/

#include "LoadedDie.hpp"

/* constructors */
LoadedDie::LoadedDie() : Die()
{

}


LoadedDie::LoadedDie(int sides) : Die(sides)
{

}

/*********************************************************************  
** Function:  roll()
** Description: Overriding function that simulates the roll of a 
**				loaded die of a given number of sides.
**  
*********************************************************************/


int LoadedDie::roll() const
{
	int val = getRandom(1, sides);

	if (val < (sides/2))
	{
		return val * 2;
	}
	else
	{
		return val;
	}
}
