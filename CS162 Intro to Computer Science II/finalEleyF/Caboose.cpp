/*********************************************************************  
** Program Filename:  Caboose.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Caboose
**				 class.
**
**
*********************************************************************/

#include "Caboose.hpp"


/* constructor */
Caboose::Caboose(std::string n)
{
	codeOnCaboose = true;
	setNameOfSpace(n);
}

/* destructor */
Caboose::~Caboose()
{

}

/* getter */

bool Caboose::getSpaceState()
{
	return codeOnCaboose;
}

/*********************************************************************  
** Function:  printDesc()
** Description: Function that prints the Space description.
**
**  
*********************************************************************/
void Caboose::printDesc()
{
	std::cout << "You are on the " << nameOfSpace << "." <<std::endl;
	std::cout << "The villian just got lifted away in a helicopter." <<std::endl;
	std::cout << "In his haste to get away he dropped his knapsack." << std::endl;
	std::cout << "--------------------------------------------" << std::endl <<std::endl;
	std::cout << "What do you want to do next?" <<std::endl;
	std::cout << "1. Go back to the " << getPLeft()->getNameOfSpace() << "." << std::endl;
	std::cout << "2. Look inside the knapsack." << std::endl;
	std::cout << "3. Jump off the back of the train to save yourself." << std::endl << std::endl;
}

/*********************************************************************  
** Function:  specialAction()
** Description: Function that performs the special action.
**
**  
*********************************************************************/
void Caboose::specialAction()
{
	codeOnCaboose = false;
}
