/*********************************************************************  
** Program Filename:  Engine.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Engine
**				 class.
**
**
*********************************************************************/

#include "Engine.hpp"


/* constructor */
Engine::Engine(std::string n)
{
	bomb = true;
	setNameOfSpace(n);
}

/* destructor */
Engine::~Engine()
{

}

/* getter */

bool Engine::getSpaceState()
{
	return bomb;
}

/*********************************************************************  
** Function:  printDesc()
** Description: Function that prints the Space description.
**
**  
*********************************************************************/
void Engine::printDesc()
{
	std::cout << "You are in the " << nameOfSpace << "." <<std::endl;
	std::cout << "The engineer is tied up and train is racing towards the station." <<std::endl;
	std::cout << "You see the bomb next to the throttle lever." <<std::endl;
	std::cout << "--------------------------------------------" << std::endl <<std::endl;
	std::cout << "What do you want to do next?" <<std::endl;
	std::cout << "1. Disarm the bomb" << std::endl;
	std::cout << "2. Talk to engineer" <<std::endl;
	std::cout << "3. Go to the " << getPRight()->getNameOfSpace() << std::endl <<std::endl;


}

/*********************************************************************  
** Function:  specialAction()
** Description: Function that performs the special action.
**
**  
*********************************************************************/
void Engine::specialAction()
{
	bomb = false;
	std::cout << "You are disarming the bomb." << std::endl <<std::endl;
}

