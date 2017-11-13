/*********************************************************************  
** Program Filename:  Bluemen.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  These are the function definitions of the Bluemen
**				 class.
**
**
*********************************************************************/

#include "Bluemen.hpp"


/* constructors */
Bluemen::Bluemen()
{
	setTypeOfCreature(BLUEMEN);
	setArmor(3);
	setStrength(12);
	setLives(1);
}

/*********************************************************************  
** Function:  attack()
** Description: Function that calculates the Bluemen attack value.
**
**  
*********************************************************************/
int Bluemen::attack()
{
	return getRandom(1, 10) + getRandom(1, 10);
}

/*********************************************************************  
** Function:  defense()
** Description: Function that calculates the Bluemen defense value.
**  
*********************************************************************/
int Bluemen::defense()
{
	// calculate defense value based on strength
	if (strength > 8)
	{
		return getRandom(1, 6) + getRandom(1, 6) + getRandom(1, 6);
	}
	else if (strength > 4)
	{
		return getRandom(1, 6) + getRandom(1, 6);
	}
	else
	{
		return getRandom(1, 6);
	}
}

