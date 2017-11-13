/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/18/16
** Description: This is the main program for Lab8. It allows a user
**				implement a doubly linked circular queue. 
**
*********************************************************************/

#include <iostream>
#include "Queue.hpp"
#include "feUtils.hpp"



int main()
{

	int 	switchChoice,
			val;
	Queue 	queue1;


	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   QUEUE OPERATIONS" << std::endl << std::endl;
		std::cout << "1. Enter a value to be added to the queue" << std::endl;
		std::cout << "2. Display first node (front) value" << std::endl;
		std::cout << "3. Remove first node (front) value" << std::endl;
		std::cout << "4. Display the queue contents" << std::endl;
		std::cout << "5. Exit Program" << std::endl;
		std::cout << std::endl << "Enter the choice of the operation that you want to utilize (1 - 4)";
		std::cout << std::endl << "or enter (5) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(5);

		//enter switch if not (4) else exit program
		if (switchChoice != 5)
		{
			switch(switchChoice)
			{
				// addBack() function
				case 1:	
						std::cout << std::endl << "Enter the value to add to the queue: ";
						val = getInt();
						while (val < 0)
						{
							std::cout << std::endl;
							std::cout << "That is not a valid value." << std::endl;
							std::cout << "The value must be a positive integer.";
							std::cout << std::endl;
							std::cout << "Enter the value to add to the queue: ";
							val = getInt();
						}

						queue1.addBack(val);

						break;

				// getFront() function
				case 2: std::cout << std::endl << queue1.getFront() << " is the first element in the queue.";
						std::cout << std::endl;
		
						break;

				// removeFront() function
				case 3:	std::cout << std::endl << queue1.removeFront() << " has been removed from the queue.";
						std::cout << std::endl;
						
						break;

				// displayQueue() function
				case 4:	queue1.displayQueue();
						
						break;
			}
		}
	}
	// Loop again if user did not choose 4 to exit
	while (switchChoice != 5);

	std::cout << std::endl << "The program is ending." << std::endl;
	std::cout << std::endl;

}