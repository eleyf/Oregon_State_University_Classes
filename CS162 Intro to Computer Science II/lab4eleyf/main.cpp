/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description: This is the main program for Lab4. It displays a menu
**				that prompts the user to select what recursive
**				function they want to use. It then prompts the user
**				for the input of the selected function and executes it.
**
*********************************************************************/

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "feUtils.hpp"
#include "recursives.hpp"


int main()
{
	const int ARRAYSIZE = 20;
	int switchChoice,
		counter;
	std::string stringInput,
				intInput;
	int intArray[ARRAYSIZE];


	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   RECURSIVE FUNCTIONS" << std::endl << std::endl;
		std::cout << "1. Reverse String Function" << std::endl;
		std::cout << "2. Sum of Array Function" << std::endl;
		std::cout << "3. Triangular Function" << std::endl;
		std::cout << "4. Exit Program" << std::endl;
		std::cout << std::endl << "Enter the choice of the function that you want to utilize (1 - 3)";
		std::cout << std::endl << "or enter (4) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(4);

		//enter switch if not (4) to exit program
		if (switchChoice != 4)
		{
			switch(switchChoice)
			{
				// Reverse String Function
				case 1:	
						std::cout << std::endl;
						std::cout << "Enter a string that you would like to see reversed: ";
						std::cin.ignore();
						getline(std::cin, stringInput);
						std::cout << std::endl;
						std::cout << "The reverse of the string is: ";
						revStr(stringInput);
						break;

				// Sum of Array Function
				case 2: 
						// initialize array to all zeros
						for (int i = 0; i < ARRAYSIZE; i++)
						{
							intArray[i] = 0;
						}

						counter = 0;

						std::cout << std::endl;
						std::cout << "This function will calculate the sum of an array of up to ";
						std::cout << ARRAYSIZE << " integers." << std::endl;
						std::cout << std::endl;
						std::cout << "Enter the each interger amount of the array seperated by a space.";
						std::cout << std::endl;
						std::cout << "Enter the # symbol to indicate the end of the array." << std::endl;
						std::cin  >> intInput;
						while (intInput != "#" && counter < ARRAYSIZE)
						{
							intArray[counter] = atoi(intInput.c_str());;
							counter++;
							std::cin >> intInput;
						}
	
						std::cout << std::endl;
						std::cout << "the sum of the array is: " << sumArray(intArray, counter) << std::endl;
						std::cout << std::endl;

						break;

				// Triangular Function
				case 3:	std::cout << std::endl << "Enter an interger to calculate its triangular: "; 
						std::cout << std::endl << "The triangular is " << tri(getInt()) << std::endl;
						std::cout << std::endl;
			}
		}
	}
	// Loop again if user did not choose 4 to exit
	while (switchChoice != 4);

	std::cout << std::endl << "The program is ending." << std::endl;
	std::cout << std::endl;

	return 0;
}