/*********************************************************************  
** Program Filename:  Ant.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  These are the function definitions of the Ant
**				 class.
**
**
*********************************************************************/

#include "Ant.hpp"


/* constructors */
Ant::Ant()
{
	setTypeOfCritter(ANT);
	setPositionX(0);
	setPositionY(0);
	setNumOfMoves(0);
}


Ant::Ant(int posX, int posY)
{
	setTypeOfCritter(ANT);
	setPositionX(posX);
	setPositionY(posY);
	setNumOfMoves(0);
}

/*********************************************************************  
** Function:  move()
** Description: Polymorphic function that moves an Ant object in a
**				given direction and updates the number of moves taken.
**
**  
*********************************************************************/
void Ant::move(Direction directionToMove)
{
	/*update coordinates according to direction moved*/
	if (directionToMove == UP)
	{
		std::cout << std::endl << "Ant is moving up" << std::endl;
		positionY --;
	}
	else if (directionToMove == RIGHT)
	{
		std::cout << std::endl << "Ant is moving right" << std::endl;
		positionX ++;
	}
	else if (directionToMove == DOWN)
	{
		std::cout << std::endl << "Ant is moving down" << std::endl;
		positionY ++;
	}
	else /*direction must be LEFT*/
	{
		std::cout << std::endl << "Ant is moving left" << std::endl;
		positionX --;
	}

	/*increment number of moves in a cycle of three*/
	if (numOfMoves == 3)
	{
		setNumOfMoves(1);
	}
	else
	{
		numOfMoves ++;
	}

}


















