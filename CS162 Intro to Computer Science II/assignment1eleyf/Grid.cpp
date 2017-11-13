/*********************************************************************  
** Program Filename:  Grid.cpp
** Author:  Frederick Eley  
** Date:  10/9/16
** Description:  These are the function definitions of the Grid
**				 class.
** 
*********************************************************************/

#include <iostream>
#include "Grid.hpp"


/* default constructor */
Grid::Grid()
{
	setRows(1);
	setCols(1);

	gridArray = new char *[rows];

	for (int i = 0; i < rows; i++)
	{
		gridArray[i] = new char[cols];
	}

	clearGrid();
}


/*********************************************************************  
** Function:  Grid constructor
** Description: Constructor that takes the the number of
**				rows and columns of a grid as parametes,
**				dynamically creates a 2D array, and initializes its
**				contents to a blank.
** Parameters:  integers for the number of rows and number of colums.
** 
*********************************************************************/
Grid::Grid(int numOfRows, int numOfCols)
{
	setRows(numOfRows);
	setCols(numOfCols);

	gridArray = new char *[rows];

	for (int i = 0; i < rows; i++)
	{
		gridArray[i] = new char[cols];
	}

	clearGrid();
}

/* setters and getters */
void Grid::setRows(int rowsIn)
{
	rows = rowsIn;
}


void Grid::setCols(int colsIn)
{
	cols = colsIn;
}


int Grid::getRows()
{
	return rows;
}


int Grid::getCols()
{
	return cols;
}


char ** Grid::getGridArray()
{
	return gridArray;
}



/*********************************************************************  
** Function:  clearGrid()
** Description:  sets each value of the array to blank.
** Parameters:  none
** Pre-Conditions:  grid object must already exist
** Post-Conditions:  all contents of array are blank
*********************************************************************/
void Grid::clearGrid()
{
	for (int i = 0; i < rows; i++)
	{	
		for (int j = 0; j < cols; j++)
		{
			gridArray[i][j] = ' ';
		}
	}
}



/*********************************************************************  
** Function:  updateLocation(int, int)
** Description:  places the Ant graphic in the current location
**				 
** Parameters:  2 integers representing the x and y coordinates.
** 
*********************************************************************/
void Grid::updateLocation(int yCoorIn, int xCoorIn)
{
	// update location
	gridArray[yCoorIn][xCoorIn] = '*';
}


/*********************************************************************  
** Function:  updateColor(int, int)
** Description: places the correct color graphic in the appropriate 
**				location.
** Parameters:  2 integers representing the x and y coordinates, and
**				an ENUM of the color.
** 
*********************************************************************/
void Grid::updateColor(int yCoorIn, int xCoorIn, Color gridColor)
{
	// update Color
	if (gridColor == WHITE)
	{
		gridArray[yCoorIn][xCoorIn] = ' ';
	}
	else
	{
		gridArray[yCoorIn][xCoorIn] = '#';
	}
}


/*********************************************************************  
** Function:  printGrid()
** Description:  prints the contents of the 2D-array.
** 
*********************************************************************/
void Grid::printGrid()
{
	/* print array */
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			std::cout << gridArray[i][j];
		}
		std::cout << std::endl;
	}
}


/*********************************************************************  
** Function:  deleteGrid()
** Description:  deallocates 2d array to prevent memory leak
** 
*********************************************************************/
void Grid::deleteGrid()
{
	for (int i = 0; i < rows; i++)
	{
		delete [] gridArray[i];
	}
	delete [] gridArray;

}
