/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description: This is the main program for Assignment 2. It
				implements a grocery shopping list that maintains
				and displays a list of items.

*********************************************************************/

#include "List.hpp"


int main()
{
	List list1;
	int switchChoice;

	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   Grocery Shopping List" << std::endl << std::endl;
		std::cout << "1. Add Items" << std::endl;
		std::cout << "2. Remove Items" << std::endl;
		std::cout << "3. Display List" << std::endl;
		std::cout << "4. Exit Program" << std::endl;
		std::cout << std::endl << "Enter the choice of what you want to do to the list (1 - 3)";
		std::cout << std::endl << "or enter (4) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(4);

		//enter switch if not (4) to exit program
		if (switchChoice != 4)
		{
			switch(switchChoice)
			{
				// Add Items
				case 1:	list1.addToList();
						break;

				// Remove last item from list
				case 2: list1.removeFromList();
						break;

				// Display Items
				case 3:	list1.printList();
			}
		}
	}
	// Loop again if user did not choose 4 to exit
	while (switchChoice != 4);

	std::cout << std::endl << "The grocery program is ending." << std::endl;
	std::cout << std::endl;


	return 0;
}