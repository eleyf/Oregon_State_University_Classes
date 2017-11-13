/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description: This is the main program for Lab6. It allows a user
**				to push to and pop from both a Stack class and a
**				Queue class. 
**
*********************************************************************/

#include <iostream>
#include "Stack.hpp"
#include "Queue.hpp"
#include "feUtils.hpp"



int main()
{

	int switchChoice;
	Stack stack1;
	Queue queue1;

	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   STACK AND QUEUE OPERATION" << std::endl << std::endl;
		std::cout << "1. Stack Operation" << std::endl;
		std::cout << "2. Queue Operation" << std::endl;
		std::cout << "3. Exit Program" << std::endl;
		std::cout << std::endl << "Enter the choice of the operation that you want to utilize (1 - 2)";
		std::cout << std::endl << "or enter (3) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(3);

		//enter switch if not (3) to exit program
		if (switchChoice != 3)
		{
			switch(switchChoice)
			{
				// Stack Operation
				case 1:
						int stackChoice;

						do
						{
							// Display menu
							std::cout << std::endl;
							std::cout << "   STACK FUNCTIONS" << std::endl << std::endl;
							std::cout << "1. Push to Stack" << std::endl;
							std::cout << "2. Pop from Stack" << std::endl;
							std::cout << "3. Return to Main Menu" << std::endl;
							std::cout << std::endl << "Enter the choice of the function that you want to utilize (1 - 2)";
							std::cout << std::endl << "or enter (3) to reutn to main menu: ";

							// Validate selection
							stackChoice = getSwitchChoice(3);

							//enter switch if not (3) to exit program
							if (stackChoice != 3)
							{
								switch(stackChoice)
								{
									// Push Function
									case 1:
											int numberIn;

											std::cout << "Enter an integer to add to the stack: ";
											stack1.push(getInt());
											break;

									// Pop Function
									case 2:
											std::cout << std::endl;
											std::cout << stack1.pop() << " has been removed from the stack." << std::endl;

											break;
								}
							}
						}
						while (stackChoice !=3);

						break;



				// Queue Operation
				case 2:
						int queueChoice;

						do
						{
							// Display menu
							std::cout << std::endl;
							std::cout << "   Queue FUNCTIONS" << std::endl << std::endl;
							std::cout << "1. Push to Queue" << std::endl;
							std::cout << "2. Pop from Queue" << std::endl;
							std::cout << "3. Return to Main Menu" << std::endl;
							std::cout << std::endl << "Enter the choice of the function that you want to utilize (1 - 2)";
							std::cout << std::endl << "or enter (3) to reutn to main menu: ";

							// Validate selection
							queueChoice = getSwitchChoice(3);

							//enter switch if not (3) to exit program
							if (queueChoice != 3)
							{
								switch(queueChoice)
								{
									// Push Function
									case 1:
											int numberIn;

											std::cout << "Enter an integer to add to the queue: ";
											queue1.push(getInt());
											break;

									// Pop Function
									case 2:
											std::cout << std::endl;
											std::cout << queue1.pop() << " has been removed from the queue." << std::endl;
											break;
								}
							}
						}
						while (queueChoice !=3);

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