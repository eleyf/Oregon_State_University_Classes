/*********************************************************************  
** Program Filename:  Train.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Train
**				 class.
**
**
*********************************************************************/

#include "Train.hpp"


/* constructor */
Train::Train()
{

}

/* destructor */
Train::~Train()
{

}

/*********************************************************************  
** Function:  play()
** Description: Function that puts an item in the heros pocket.
**
**  
*********************************************************************/
void Train::play()
{
	//Link all the spaces together 
	eng1.setPRight(cab1);
	cab1.setPLeft(eng1);
	cab1.setPRight(cab2);
	cab1.setPTop(rf1);
	cab2.setPLeft(cab1);
	cab2.setPRight(boos1);
	cab2.setPTop(rf2);
	rf1.setPBottom(cab1);
	rf2.setPBottom(cab2);
	boos1.setPLeft(cab2);


	currentSpace = &cab1;
	moveCounter = 20;

	std::cout << "\033[2J\033[1;1H";

	do
	{
		hero1.displayPocket();
		std::cout << std::endl;
		std::cout << "TIME LEFT ON CLOCK: " << moveCounter << " minutes.";
		std::cout << std::endl;
		currentSpace->printDesc();
		moveChoice = getSwitchChoice(3);
		std::cout << "\033[2J\033[1;1H";
		

		// Front Cabin
		if (currentSpace == &cab1)
		{
			// if the hero has the key unlock the door
			if (hero1.searchPocket("engine key"))
			{
				currentSpace->specialAction();
			}

			switch(moveChoice)
				{
					// Go to front of train
					case 1:	
							// Check if door is locked
							if (currentSpace->getSpaceState())
							{
								std::cout << "The door to the engine is locked." << std::endl;
								std::cout << "Hurry and find the key." << std::endl << std::endl;
							}
							// If unlocked move to engine
							else
							{	
								currentSpace = currentSpace->getPLeft();
							}
							break;


					// Climb to roof of train
					case 2:	
							currentSpace = currentSpace->getPTop();
							
							break;

					// Go to back of train
					case 3: 
							currentSpace = currentSpace->getPRight();

							break;
				}
		}


		// Rear Cabin
		else if (currentSpace == &cab2)
		{
			// if the hero has the key unlock the door
			if (hero1.searchPocket("cabin key"))
			{
				currentSpace->specialAction();
			}

			switch(moveChoice)
				{
					// Go to front of train
					case 1:	
							// Check if door is locked
							if (currentSpace->getSpaceState())
							{
								std::cout << "The door to the front cabin is locked." << std::endl;
								std::cout << "Hurry and find the key." << std::endl << std::endl;
							}
							// If unlocked move to engine
							else
							{	
								currentSpace = currentSpace->getPLeft();
							}
							break;

					// Climb to roof of train
					case 2:	
							currentSpace = currentSpace->getPTop();
							
							break;

					// Go to back of train
					case 3: 
							currentSpace = currentSpace->getPRight();

							break;
				}
		}


		// Front Roof
		else if (currentSpace == &rf1)
		{
			switch(moveChoice)
				{
					// Look in compartment
					case 1:	
							// If key is in comparment
							if (currentSpace->getSpaceState())
							{
								std::cout << "You found the key to the engine room." << std::endl;
								hero1.putInPocket("engine key");
								currentSpace->specialAction();
							}
							// If already picked up key
							else
							{	
								std::cout << "The compartment is empty, ";
								std::cout << "you already have the key in your pocket.";
								std::cout << std::endl << std::endl;
							}
							break;

					// Go to back down to cabin
					case 2: 
							currentSpace = currentSpace->getPBottom();

							break;

					// Climb to roof of train
					case 3:	
							std::cout << "The gusts of wind are too strong to jump." << std::endl;
							std::cout << "It might be easier to walk through the cabins.";
							std::cout << std::endl << std::endl;
							
							break;
				}
		}


		// Rear Roof
		else if (currentSpace == &rf2)
		{
			switch(moveChoice)
				{
					// Look in compartment
					case 1:	
							// If key is in comparment
							if (currentSpace->getSpaceState())
							{
								std::cout << "You found the key to the front cabin." << std::endl;
								hero1.putInPocket("cabin key");
								currentSpace->specialAction();
							}
							// If already picked up key
							else
							{	
								std::cout << "The compartment is empty, ";
								std::cout << "you already have the key in your pocket.";
								std::cout << std::endl << std::endl;
							}
							break;

					// Go to back down to cabin
					case 2: 
							currentSpace = currentSpace->getPBottom();

							break;

					// Climb to roof of train
					case 3:	
							std::cout << "The gusts of wind are too strong to jump." << std::endl;
							std::cout << "It might be easier to walk through the cabins.";
							std::cout << std::endl << std::endl;
							
							break;
				}
		}


		// Engine
		else if (currentSpace == &eng1)
		{
			switch(moveChoice)
				{
					// Deactivate bomb
					case 1:	
							// If you have the deactivation code
							if (hero1.searchPocket("coded usb"))
							{
								currentSpace->specialAction();
							}
							// If already picked up key
							else
							{	
								std::cout << "The bomb has been set to detonate if the wires are cut, ";
								std::cout << "it can only be deactivated with a specially coded usb stick.";
								std::cout << std::endl << std::endl;
							}
							break;

					// Talk to the enginner
					case 2: 
							std::cout << "The engineer has fainted." << std::endl;
							std::cout << "Hurry the clock is ticking.";
							std::cout << std::endl << std::endl;

							break;

					// Go to front cabin
					case 3:	
							currentSpace = currentSpace->getPRight();
							
							break;
				}
		}


		// Caboose
		else if (currentSpace == &boos1)
		{
			switch(moveChoice)
				{
					// Go back into cabin
					case 1:	
							currentSpace = currentSpace->getPLeft();

							break;

					// Look in the knapsack
					case 2:	
							// If code is in the knapsack
							if (currentSpace->getSpaceState())
							{
								std::cout << "You found the coded usb stick." << std::endl;
								hero1.putInPocket("coded usb");
								currentSpace->specialAction();
							}
							// If already picked up key
							else
							{	
								std::cout << "The knapsack is empty, ";
								std::cout << "you already have the coded usb stick in your pocket.";
								std::cout << std::endl << std::endl;
							}
							
							break;

					// Jump of train
					case 3:	
							std::cout << "The train is moving too fast to jump." << std::endl;
							std::cout << "If you do you'll surely perish." << std::endl;
							std::cout << "Better find a better solution.";
							std::cout << std::endl << std::endl;							
							
							break;
				}
		}

		moveCounter--;
	}
	while (moveCounter > 0 && eng1.getSpaceState());


	// If the bomb is still activated it explodes
	if (eng1->getSpaceState())
	{
		std::cout << std::endl;
		std::cout << "BOOOOOOOOOMMMMM!!!!!!!!!!!!!!" << std::endl;
		std::cout << "You failed to disarm the bomb in time." << std::endl;
	}
	else 
	{
		std::cout << std::endl;
		std::cout << "YOU HAVE SAVED THE DAY!!!!!!!!!!!!!!" << std::endl;
		std::cout << "You disarmed the bomb in just in time." << std::endl;
	}
}


