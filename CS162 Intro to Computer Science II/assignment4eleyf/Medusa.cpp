/*********************************************************************  
** Program Filename:  Medusa.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  These are the function definitions of the Medusa
**				 class.
**
**
*********************************************************************/

#include "Medusa.hpp"


/* constructors */
Medusa::Medusa()
{
	setTypeOfCreature(MEDUSA);
	setArmor(3);
	setStrength(8);
	setLives(1);
}

/*********************************************************************  
** Function:  attack()
** Description: Function that calculates the Medusa attack value.
**
**  
*********************************************************************/
int Medusa::attack()
{
	int attackVal;
	attackVal = getRandom(1, 6) + getRandom(1, 6);
	// if attackVal equals twelve return -1 as a flag to use Glare
	if (attackVal == 12)
	{
		return -1;
	}
	// else return regular attack value
	else
	{
		return attackVal;
	}
}

/*********************************************************************  
** Function:  defense()
** Description: Function that calculates the Medusa defense value.
**  
*********************************************************************/
int Medusa::defense()
{
	return getRandom(1, 6);
}
