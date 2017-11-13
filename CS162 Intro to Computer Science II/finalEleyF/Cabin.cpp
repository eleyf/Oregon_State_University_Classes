/*********************************************************************  
** Program Filename:  Cabin.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Cabin
**				 class.
**
**
*********************************************************************/

#include "Cabin.hpp"


/* constructor */
Cabin::Cabin(std::string n)
{
	doorLocked = true;
	setNameOfSpace(n);
}

/* destructor */
Cabin::~Cabin()
{

}

/* getter */

bool Cabin::getSpaceState()
{
	return doorLocked;
}

/*********************************************************************  
** Function:  printDesc()
** Description: Function that prints the Space description.
**
**  
*********************************************************************/
void Cabin::printDesc()
{
	std::cout << "You are in the " << nameOfSpace << "." <<std::endl;
	std::cout << "You see a doors in the front and rear of the car." <<std::endl;
	std::cout << "The conductor is bound and gagged but motions with his eyes ";
	std::cout << "to a hatch above your head." <<std::endl;
	std::cout << "--------------------------------------------" << std::endl <<std::endl;
	std::cout << "What do you want to do next?" <<std::endl;
	std::cout << "1. Go into the " << getPLeft()->getNameOfSpace() << std::endl;
	std::cout << "2. Climb up onto the " << getPTop()->getNameOfSpace() << std::endl;
	std::cout << "3. Go into the " << getPRight()->getNameOfSpace() << std::endl << std::endl;
}

/*********************************************************************  
** Function:  specialAction()
** Description: Function that performs the special action.
**
**  
*********************************************************************/
void Cabin::specialAction()
{
	doorLocked = false;
	std::cout << "You are unlocking the door." << std::endl <<std::endl;
}
