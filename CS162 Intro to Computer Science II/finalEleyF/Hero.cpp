/*********************************************************************  
** Program Filename:  Hero.cpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  These are the function definitions of the Hero
**				 class.
**
**
*********************************************************************/

#include "Hero.hpp"


/* constructor */
Hero::Hero()
{
	for (int i = 0; i < 3; i++)
	{
		pocket[i] = " ";
	}

}

/* destructor */
Hero::~Hero()
{

}

/*********************************************************************  
** Function:  putInPocket()
** Description: Function that puts an item in the heros pocket.
**
**  
*********************************************************************/
void Hero::putInPocket(std::string n)
{
	pocket[pocketIndex] = n;
	std::cout << "You put the " << n << " in your pocket." << std::endl;
	pocketIndex++;
}

/*********************************************************************  
** Function:  displayPocket()
** Description: Function that displays the contents of the Hero's
**				pockets.
**
**  
*********************************************************************/
void Hero::displayPocket()
{
	std::cout << "Items in pockets: ";
	if (pocketIndex == 0 && pocket[0] == " ")
	{
		std::cout << "You have nothing in your pockets." << std::endl;
	}
	else
	{
		for (int i = 0; i < pocketIndex; i++)
		{
			std::cout << pocket[i] << ", ";
		}
	}
	std::cout << std::endl;
}

/*********************************************************************  
** Function:  searchPocket()
** Description: Function that searches the pocket array for an item
**				and returns true if found. If it is not in the array
**				a value of false is returned.
**
**  
*********************************************************************/
bool Hero::searchPocket(std::string n)
{
	for(int i = 0; i < pocketIndex; i++)
	{
		if(pocket[i] == n) 
			{
				return true;
			}
	}
	return false;
}



