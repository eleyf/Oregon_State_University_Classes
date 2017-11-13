/**********************************************
**
**	Author: Frederick Eley
**	Date:	10/16/16
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
**  returns its value. MUST HAVE <cstdlib> AND
**	<ctime> #included in main.
**
**********************************************/

//from 0 to max
int getRandom(int max)
{
	return rand()% max;
}

// range of lo - hi
int	getRandom(int low, int hi)
{
	return (rand()% (hi - low + 1)) + low;
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
	int num; //variable to store the number entered by the user.

	//Read already prompted input.
	std::cin >> num;

	//While the input entered is not an integer, prompt the user to enter an integer.
	while(std::cin.fail())
	{
	    std::cout << "That is not a valid input. Please enter an integer: ";
	    std::cin.clear();
	    std::cin.ignore();
	    std::cin >> num;
	}

	return num;
}



