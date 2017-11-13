/*********************************************************************  
** Program Filename:  Grid.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  These are the function definitions of the Grid
**				 class.
**
*********************************************************************/

#include "Grid.hpp"


/* constructors */
Grid::Grid()
{
	setRowsY(2);
	setColsX(2);

	gridArray = new Critter **[rowsY];
	for (int i = 0; i < rowsY; i++)
	{
		gridArray[i] = new Critter *[colsX];
		for (int j = 0; j < colsX; j++)
		{
			gridArray[i][j] = NULL;
		}
	}
}

Grid::Grid(int rY, int cX)
{
	setRowsY(rY);
	setColsX(cX);

	gridArray = new Critter **[rowsY];
	for (int i = 0; i < rowsY; i++)
	{
		gridArray[i] = new Critter *[colsX];
		for (int j = 0; j < colsX; j++)
		{
			gridArray[i][j] = NULL;
		}
	}
}

Grid::~Grid()
{
	// for( int i = 0; i < rowsY; i++)
	// {
	//     delete [] gridArray[i];
	// }
	// delete [] gridArray;
	// gridArray = NULL;


	for(int i = 0; i < rowsY; i++)
	{
        for(int j = 0; j < colsX; j++)
        {
            delete [] gridArray[i][j];
        }

        delete [] gridArray[i];
    }
    delete [] gridArray;
    // gridArray = NULL;
}


/*Grid =Operator Overload*/
Grid Grid::operator=(const Grid &right)
{
	std::cout << "overload operator" << std::endl;

	// for( int i = 0; i < rowsY; i++)
	// {
	//     delete [] gridArray[i];
	// }
	// delete [] gridArray;
	// gridArray = NULL;

	for(int i = 0; i < rowsY; i++)
	{
		for(int j = 0; j < colsX; j++)
		{
	    	if(gridArray[i][j]);
	    	delete [] gridArray[i][j];
	    }
	    delete [] gridArray[i];
	   }
	delete [] gridArray;
    gridArray = NULL;

	std::cout << "overload operator 2" << std::endl;
	rowsY = right.rowsY;
	colsX = right.colsX;

	gridArray = new Critter **[rowsY];
	for (int i = 0; i < rowsY; i++)
	{
		gridArray[i] = new Critter *[colsX];
		for (int j = 0; j < colsX; j++)
		{
			if (right.gridArray[i][j])
			{
				if ((right.gridArray[i][j])->getTypeOfCritter() == ANT)
					{
						gridArray[i][j] = new Ant((right.gridArray[i][j])->getPositionX(), (right.gridArray[i][j])->getPositionY()); 
					}
					else
					{
						gridArray[i][j] = new Doodlebug((right.gridArray[i][j])->getPositionX(), (right.gridArray[i][j])->getPositionY());
					}
				}
			else
			{
				gridArray[i][j] = NULL;
			}
		}
	}

	std::cout << "overload operator 3" << std::endl;
	
	return *this;
}




/* setters and getters */
void Grid::setRowsY(int r)
{
	this->rowsY = r;
}

void Grid::setColsX(int c)
{
	this->colsX = c;
}

Critter *** Grid::getGridArray()
{
	return gridArray;
}



/*********************************************************************  
** Function:  createAnt()
** Description: Function that creates a new Ant object.
**
**  
*********************************************************************/
void Grid::createAnt(int x, int y)
{
	std::cout << std::endl << "Creating Ant" << std::endl;
	gridArray[y][x] = new Ant(x, y);
}

/*********************************************************************  
** Function:  createDoodlebug()
** Description: Function that creates a new Doodlebug object.
**
**  
*********************************************************************/
void Grid::createDoodlebug(int x, int y)
{
	std::cout << std::endl << "Creating Doodlebug" << std::endl;
	gridArray[y][x] = new Doodlebug(x, y);
}

/*********************************************************************  
** Function:    safeMove(Direction d);
** Description: Function that tests if the next move is valid.
**
**  
*********************************************************************/
bool    Grid::safeMove(Direction d)
{
	bool safe = true;
}

/*********************************************************************  
** Function:  displayGrid()
** Description: Function that displays a grid.
**
**  
*********************************************************************/
void Grid::displayGrid() const
{
	std::cout << std::endl << "Grid is displayed" << std::endl;

		/* print header row */
	std::cout << std::endl;
	std::cout <<  ' ';
	for ( int i = 0; i < colsX; i++)
	{
		std::cout << ' ' << '-' << ' ';
	}
	std::cout << ' ' << std::endl;

	/* print array */
	for (int i = 0; i < rowsY; i++)
	{
		std::cout << '<';
		for (int j = 0; j < colsX; j++)
		{
			if (gridArray[i][j]) /*if a Critter is pointed to determine type and print*/
			{
				if (gridArray[i][j]->getTypeOfCritter() == ANT)
				{
					std::cout << " O ";
				}
				if (gridArray[i][j]->getTypeOfCritter() == DOODLE)
				{
					std::cout << " X ";
				}

			}
			else	/*pointer is NULL so space is empty*/
			{
				std::cout << " E ";
			}

		}
		std::cout << '>' << std::endl;
	}

	/* print bottom row */
	std::cout <<  ' ';
	for ( int i = 0; i < colsX; i++)
	{
		std::cout << ' ' << '-' << ' ';
	}
	std::cout << ' ' << std::endl;	

}







