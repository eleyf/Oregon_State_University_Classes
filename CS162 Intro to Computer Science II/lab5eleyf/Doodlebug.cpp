/*********************************************************************  
** Program Filename:  Doodlebug.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  These are the function definitions of the Doodlebug
**				 class.
**
*********************************************************************/

#include "Doodlebug.hpp"


/* constructors */
Doodlebug::Doodlebug()
{
	setTypeOfCritter(DOODLE);
	setPositionX(0);
	setPositionY(0);
	setNumOfMoves(0);
}


Doodlebug::Doodlebug(int posX, int posY)
{
	setTypeOfCritter(DOODLE);
	setPositionX(posX);
	setPositionY(posY);
	setNumOfMoves(0);
}


/*********************************************************************  
** Function:  move()
** Description: Polymorphic function that moves a Doodlebug object in
**				a given direction and updates the number of moves 
**				taken.
**  
*********************************************************************/
void Doodlebug::move(Direction directionToMove)
{
	std::cout << std::endl << "Doodlebug is moving" << std::endl;

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
	if (numOfMoves == 8)
	{
		setNumOfMoves(1);
	}
	else
	{
		numOfMoves ++;
	}

}
