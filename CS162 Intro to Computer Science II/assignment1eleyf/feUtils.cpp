/**********************************************
**
**	Author: Frederick Eley
**	Date:	10/9/16
**	Description:	Utility functions.
**
**********************************************/



#include "feUtils.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>


/*********************************************
**
**			getRandom()
**
**	Function that takes an interger as a
**	parameter. It generates a random integer
**  less than the parameter entered and 
**  returns its value.
**
**********************************************/


int getRandom(int max)
{
	/* create seed for random number generator */
	unsigned seed;
	seed = time(0);
	srand(seed);

	return rand()% max;
}


/*********************************************
**
**			getSwitchChoice()
**
**	Function that takes the number of choices
**	in a swith as a parameter. It prompts the
**	user to make a choice and returns the
**	value of that choice.
**
**********************************************/


int getSwitchChoice(int numOfChoices)
{
	int choice;

	std::cout << " Enter Your Choice: ";
	choice = getInt();

	while (choice < 1 || choice > numOfChoices)
	{
		std::cout << std::endl;
		std::cout << "That is not a valid option." << std::endl;
		std::cout << "Choose an option between 1 and " << numOfChoices << ".";
		std::cout << std::endl;
		std::cout << "Enter Your Choice:";
		std::cin  >> choice;
	}


	return choice;
}

/*********************************************
**
**			getInt()
**
**	Function that reads a users input and
**	verifies if it is an integer. If it is not
**	it prompts the user to enter an valid
**	integer. It returns a verified integer.
**
**********************************************/


int getInt()
{
	int input;

	std::cin  >> input;
	std::cin.ignore();
	while(input != static_cast<int>(input))
	{
		std::cout << "That is not a valid integer." << std::endl;
		std::cout << "Enter an integer value: ";
		std::cin  >> input;
		std::cin.ignore();
	}

	return static_cast<int>(input);
}



