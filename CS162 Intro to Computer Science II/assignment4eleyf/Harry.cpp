/*********************************************************************  
** Program Filename:  Harry.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  These are the function definitions of the Harry
**				 class.
**
**
*********************************************************************/

#include "Harry.hpp"


/* constructors */
Harry::Harry()
{
	setTypeOfCreature(HARRY);
	setArmor(0);
	setStrength(10);
	setLives(2);
}

/*********************************************************************  
** Function:  attack()
** Description: Function that calculates the Harry attack value.
**
**  
*********************************************************************/
int Harry::attack()
{
	return getRandom(1, 6) + getRandom(1, 6);
}

/*********************************************************************  
** Function:  defense()
** Description: Function that calculates the Harry defense value.
**  
*********************************************************************/
int Harry::defense()
{
	return getRandom(1, 6);
}
