/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/27/16
** Description: This is the main program for Lab9. It implements a STL
**				queue to simulate a buffer and a STL stack to create
**				a palindrome.
**
*********************************************************************/

#include <iostream>
#include <string>
#include "feUtils.hpp"
#include "Stack.hpp"
#include "Buffer.hpp"
#include <cstdlib>
#include <ctime>


int main()
{
	int switchChoice,
		percentIn,
		percentOut,
		roundCounter,
		lengthTotals;
	double avgLength;
	Buffer b1;
	Stack s1;
	std::string stringIn;
	srand(time(NULL));


	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   STL CONTAINERS" << std::endl << std::endl;
		std::cout << "1. Buffer Simulator" << std::endl;
		std::cout << "2. Palindrome" << std::endl;
		std::cout << "3. Exit Program" << std::endl;
		std::cout << std::endl << "Enter the choice of the function that you want to utilize (1 - 2)";
		std::cout << std::endl << "or enter (3) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(3);

		//enter switch if not (3) else exit program
		if (switchChoice != 3)
		{
			switch(switchChoice)
			{
				// Buffer Simulator
				case 1:	
						lengthTotals = 0;

						// get percentage to add
						std::cout << std::endl;
						std::cout << "Enter the percentage of numbers added to the buffer (0 - 100):" << std::endl;
						percentIn = getInt();
						while (percentIn < 0 || percentIn > 100)
						{
							std::cout << "That is not a valid percentage. Choose a percentage between 0 and 100.";
							std::cout << std::endl << std::endl;
							std::cout << "Enter the percentage of numbers added to the buffer (0 - 100):" << std::endl;
							percentIn = getInt();
						}

						// get percentage to remove
						std::cout << std::endl;
						std::cout << "Enter the percentage of numbers removed from the buffer (0 - 100):" << std::endl;
						percentOut = getInt();
						while (percentOut < 0 || percentOut > 100)
						{
							std::cout << "That is not a valid percentage. Choose a percentage between 0 and 100.";
							std::cout << std::endl << std::endl;
							std::cout << "Enter the percentage of numbers removed from the buffer (0 - 100):" << std::endl;
							percentOut = getInt();
						}

						// get number of rounds
						std::cout << std::endl;
						std::cout << "Enter the number of rounds to run the buffer simulation:" << std::endl;
						roundCounter = getInt();


						for (int i = 1; i <= roundCounter; i++)
						{
							std::cout << "Round " << i << ": " << std::endl;
							b1.bufferPush(percentIn);
							std::cout << "Buffer size after attempt to add: " << b1.bufferSize() << std::endl;

							if (! b1.bufferEmpty())
							{
								b1.bufferPop(percentOut);
							}
							std::cout << "Buffer size after attempet to remove: " << b1.bufferSize() << std::endl;

							lengthTotals = lengthTotals + b1.bufferSize();

							avgLength = double(lengthTotals)/ double(i);
							
							std::cout << "Average length: " << avgLength << std::endl << std::endl;
						}

						b1.bufferClear();

						break;

				// Palindrome
				case 2: 
						std::cout << "Enter a string of characters to find its palindrome." << std::endl;
						std::cin  >> stringIn;
						std::cout << std::endl;
						std::cout << "The palindrome is " << s1.pal(stringIn) << std::endl << std::endl;

						break;
			}
		}
	}
	// Loop again if user did not choose 3 to exit
	while (switchChoice != 3);

	std::cout << std::endl << "The program is ending." << std::endl;
	std::cout << std::endl;

	return 0;
}