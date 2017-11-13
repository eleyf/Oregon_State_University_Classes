/*********************************************************************  
** Program Filename:  Vampire.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  These are the function definitions of the Vampire
**				 class.
**
**
*********************************************************************/

#include "Vampire.hpp"


/* constructors */
Vampire::Vampire()
{
	setTypeOfCreature(VAMPIRE);
	setArmor(1);
	setStrength(18);
	setLives(1);
}

/*********************************************************************  
** Function:  attack()
** Description: Function that calculates the vampire attack value.
**
**  
*********************************************************************/
int Vampire::attack()
{
	return getRandom(1, 12);
}

/*********************************************************************  
** Function:  defense()
** Description: Function that calculates the vampire defense value.
**  
*********************************************************************/
int Vampire::defense()
{
	// if random number is one return flag value of -1
	// that will nullify the attack.
	if (getRandom(0, 1))
		return -1;
	else
		return getRandom(1, 6);
}

