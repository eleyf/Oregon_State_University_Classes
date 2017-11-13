/*********************************************************************  
** Program Filename:  Barbarian.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  These are the function definitions of the Barbarian
**				 class.
**
**
*********************************************************************/

#include "Barbarian.hpp"


/* constructors */
Barbarian::Barbarian()
{
	setTypeOfCreature(BARBARIAN);
	setArmor(0);
	setStrength(12);
	setLives(1);
}

/*********************************************************************  
** Function:  attack()
** Description: Function that calculates the barbarian attack value.
**
**  
*********************************************************************/
int Barbarian::attack()
{
	return getRandom(1, 6) + getRandom(1, 6);
}

/*********************************************************************  
** Function:  defense()
** Description: Function that calculates the barbarian defense value.
**
**  
*********************************************************************/
int Barbarian::defense()
{
	return getRandom(1, 6) + getRandom(1, 6);
}


