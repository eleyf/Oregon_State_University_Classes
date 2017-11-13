/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description: This is the main program for Assignment 3. It uses
**				an abstact class Creature as a parent class to 
**				create polymorphic characters that battle one another.
**
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>


#include "World.hpp"


int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	World w1;
	
	int gameChoice;

	do
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   COMBAT GAME" << std::endl << std::endl;
		std::cout << "1. Play Game" << std::endl;
		std::cout << "2. Exit Game" << std::endl;
		std::cout << std::endl << "Enter (1) to play";
		std::cout << std::endl << "or enter (2) to reutn to exit the game: ";

		// Validate selection
		gameChoice = getSwitchChoice(2);

		//enter switch if not (2) to exit program
		if (gameChoice != 2)
		{
			w1.play();
		}
	}
	while (gameChoice !=2);

	std::cout << std::endl << "Thanks for playing." << std::endl;
	std::cout << std::endl;

	return 0;
}