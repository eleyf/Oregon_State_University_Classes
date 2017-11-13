/*********************************************************************  
** Program Filename:  Roof.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Roof
**				 class.
**
**
*********************************************************************/

#include "Roof.hpp"


/* constructor */
Roof::Roof(std::string n)
{
	keyOnRoof = true;
	setNameOfSpace(n);
}

/* destructor */
Roof::~Roof()
{

}

/* getter */

bool Roof::getSpaceState()
{
	return keyOnRoof;
}

/*********************************************************************  
** Function:  printDesc()
** Description: Function that prints the Space description.
**
**  
*********************************************************************/
void Roof::printDesc()
{
	std::cout << "You are on the " << nameOfSpace << "." <<std::endl;
	std::cout << "A gust of wind knocks you down." <<std::endl;
	std::cout << "In the corner of your eye you notice a secret compartment." << std::endl;
	std::cout << "--------------------------------------------" << std::endl <<std::endl;
	std::cout << "What do you want to do next?" <<std::endl;
	std::cout << "1. Open the compartment" << std::endl;
	std::cout << "2. Go back down into the " << getPBottom()->getNameOfSpace() << std::endl;
	std::cout << "3. Try to jump to the next car" << std::endl << std::endl;
}

/*********************************************************************  
** Function:  specialAction()
** Description: Function that performs the special action.
**
**  
*********************************************************************/
void Roof::specialAction()
{
	keyOnRoof = false;
}
