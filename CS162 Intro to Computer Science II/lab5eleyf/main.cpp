/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description: This is the main program for Lab5. It uses polymorphism
**				to move the Ant and Doodlebug classes.
**
*********************************************************************/

#include <iostream>
#include "Grid.hpp"


int main()
{


	Grid mainGrid(20, 20);
	Grid tempGrid(20, 20);


	mainGrid.createAnt(3, 6);
	mainGrid.createDoodlebug(10, 13);
	mainGrid.displayGrid();


	tempGrid.displayGrid();



/*used to move a cell*/	

	std::cout << "Ant X(3): " << (mainGrid.getGridArray())[6][3]->getPositionX() << std::endl;
	std::cout << "Ant Y(6): " << (mainGrid.getGridArray())[6][3]->getPositionY() << std::endl;
	std::cout << "Ant NOM:(0) " << (mainGrid.getGridArray())[6][3]->getNumOfMoves() << std::endl;

	std::cout << "Dood X(10): " << (mainGrid.getGridArray())[13][10]->getPositionX() << std::endl;
	std::cout << "Dood Y(13): " << (mainGrid.getGridArray())[13][10]->getPositionY() << std::endl;
	std::cout << "Dood NOM:(0) " << (mainGrid.getGridArray())[13][10]->getNumOfMoves() << std::endl;


// step 1
	(mainGrid.getGridArray())[6][3]->move(UP);
	(mainGrid.getGridArray())[13][10]->move(UP);

	std::cout << "Ant X:(3) " << (mainGrid.getGridArray())[6][3]->getPositionX() << std::endl;
	std::cout << "Ant Y:(5) " << (mainGrid.getGridArray())[6][3]->getPositionY() << std::endl;
	std::cout << "Ant NOM:(1) " << (mainGrid.getGridArray())[6][3]->getNumOfMoves() << std::endl;


	std::cout << "Dood X(10): " << (mainGrid.getGridArray())[13][10]->getPositionX() << std::endl;
	std::cout << "Dood Y(12): " << (mainGrid.getGridArray())[13][10]->getPositionY() << std::endl;
	std::cout << "Dood NOM:(1) " << (mainGrid.getGridArray())[13][10]->getNumOfMoves() << std::endl;


// step2
	(mainGrid.getGridArray())[6][3]->move(RIGHT);
	(mainGrid.getGridArray())[13][10]->move(RIGHT);

	std::cout << "Ant X:(4) " << (mainGrid.getGridArray())[6][3]->getPositionX() << std::endl;
	std::cout << "Ant Y:(5) " << (mainGrid.getGridArray())[6][3]->getPositionY() << std::endl;
	std::cout << "Ant NOM:(2) " << (mainGrid.getGridArray())[6][3]->getNumOfMoves() << std::endl;

	std::cout << "Dood X(11): " << (mainGrid.getGridArray())[13][10]->getPositionX() << std::endl;
	std::cout << "Dood Y(12): " << (mainGrid.getGridArray())[13][10]->getPositionY() << std::endl;
	std::cout << "Dood NOM:(2) " << (mainGrid.getGridArray())[13][10]->getNumOfMoves() << std::endl;

// step 3	
	(mainGrid.getGridArray())[6][3]->move(DOWN);
	(mainGrid.getGridArray())[13][10]->move(DOWN);

	std::cout << "Ant X:(4) " << (mainGrid.getGridArray())[6][3]->getPositionX() << std::endl;
	std::cout << "Ant Y:(6) " << (mainGrid.getGridArray())[6][3]->getPositionY() << std::endl;
	std::cout << "Ant NOM:(3) " << (mainGrid.getGridArray())[6][3]->getNumOfMoves() << std::endl;

	std::cout << "Dood X(11): " << (mainGrid.getGridArray())[13][10]->getPositionX() << std::endl;
	std::cout << "Dood Y(13): " << (mainGrid.getGridArray())[13][10]->getPositionY() << std::endl;
	std::cout << "Dood NOM:(3) " << (mainGrid.getGridArray())[13][10]->getNumOfMoves() << std::endl;


// step 4	
	(mainGrid.getGridArray())[6][3]->move(LEFT);
	(mainGrid.getGridArray())[13][10]->move(LEFT);

	std::cout << "Ant X:(3) " << (mainGrid.getGridArray())[6][3]->getPositionX() << std::endl;
	std::cout << "Ant Y:(6) " << (mainGrid.getGridArray())[6][3]->getPositionY() << std::endl;
	std::cout << "Ant NOM:(1) " << (mainGrid.getGridArray())[6][3]->getNumOfMoves() << std::endl;


	std::cout << "Dood X(10): " << (mainGrid.getGridArray())[13][10]->getPositionX() << std::endl;
	std::cout << "Dood Y(13): " << (mainGrid.getGridArray())[13][10]->getPositionY() << std::endl;
	std::cout << "Dood NOM:(4) " << (mainGrid.getGridArray())[13][10]->getNumOfMoves() << std::endl;


// step 5
	(mainGrid.getGridArray())[6][3]->move(DOWN);
	(mainGrid.getGridArray())[13][10]->move(DOWN);

	std::cout << "Ant X:(3) " << (mainGrid.getGridArray())[6][3]->getPositionX() << std::endl;
	std::cout << "Ant Y:(7) " << (mainGrid.getGridArray())[6][3]->getPositionY() << std::endl;
	std::cout << "Ant NOM:(2) " << (mainGrid.getGridArray())[6][3]->getNumOfMoves() << std::endl;

	std::cout << "Dood X(10): " << (mainGrid.getGridArray())[13][10]->getPositionX() << std::endl;
	std::cout << "Dood Y(14): " << (mainGrid.getGridArray())[13][10]->getPositionY() << std::endl;
	std::cout << "Dood NOM:(5) " << (mainGrid.getGridArray())[13][10]->getNumOfMoves() << std::endl;



	


	/*used to update temp grid*/
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (mainGrid.getGridArray()[i][j]) /*if a Critter is pointed to determine type and print*/
			{
				if (((mainGrid.getGridArray()[i][j])->getTypeOfCritter()) == ANT)
				{
					tempGrid.getGridArray()[i][j] = new Ant((mainGrid.getGridArray()[i][j])->getPositionX(), (mainGrid.getGridArray()[i][j])->getPositionY()); 
				}
				else
				{
					tempGrid.getGridArray()[i][j] = new Doodlebug((mainGrid.getGridArray()[i][j])->getPositionX(), (mainGrid.getGridArray()[i][j])->getPositionY());
				}
			}
			else	/*pointer is NULL*/
			{
				tempGrid.getGridArray()[i][j] = NULL;
			}
		}
	}


	tempGrid.displayGrid();

	return 0;
}
