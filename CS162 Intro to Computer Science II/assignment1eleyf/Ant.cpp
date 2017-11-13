/*********************************************************************  
** Program Filename:  Ant.cpp
** Author:  Frederick Eley  
** Date:  10/9/16
** Description:  These are the function definitions of the Ant
**				 class.
** Input:	The default constructor sets the x and y coordinates to
**			0, the initial direction to north, and the initial color
**			to white.
**			Another constructor takes in the x and y coordinates as 
**		  	parameters, sets the initial direction to north, and the
**			initial color to white.
**
*********************************************************************/

#include "Ant.hpp"
#include <cstdlib>
#include <ctime>

/* constructors */
Ant::Ant()
{
	setMaxRows(1);
	setMaxCols(1);
	setXCoor(0);
	setYCoor(0);
	setNumOfMoves(0);
	setSqColor(WHITE);
	setAntDirection(NORTH);
}


Ant::Ant(int yIn, int xIn, int maxRowsIn, int maxColsIn)
{
	setMaxRows(maxRowsIn);
	setMaxCols(maxColsIn);
	setXCoor(xIn);
	setYCoor(yIn);
	setNumOfMoves(0);
	setSqColor(WHITE);
	setAntDirection(NORTH);
}

/* setters and getters */
void Ant::setMaxRows(int maxRowsIn)
{
	maxRows = maxRowsIn;
}


void Ant::setMaxCols(int maxColsIn)
{
	maxCols = maxColsIn;
}


void Ant::setXCoor(int xCoorIn)
{
	xCoor = xCoorIn;
}


void Ant::setYCoor(int yCoorIn)
{
	yCoor = yCoorIn;
}


void Ant::setNumOfMoves(int numOfMovesIn)
{
	numOfMoves = numOfMovesIn;
}


void Ant::setSqColor(Color sqColorIn)
{
	sqColor = sqColorIn;
}

void Ant::setAntDirection(Direction antDirectionIn)
{
	antDirection = antDirectionIn;
}

int Ant::getXCoor()
{
	return xCoor;
}


int Ant::getYCoor()
{
	return yCoor;
}


int Ant::getNumOfMoves()
{
	return numOfMoves;
}


Color Ant::getSqColor()
{
	return sqColor;
}

Direction Ant::getAntDirection()
{
	return antDirection;
}


/*********************************************************************  
** Function:  turn()
** Description:  Function that turns the direction the Ant is facing.
**
** Parameters:  ENUM of current directin, ENUM of current square color.
**  
*********************************************************************/
void Ant::turn(Direction currentDirection, Color currentColor)
{

	if (currentDirection == NORTH)
	{
		if (currentColor == WHITE)
		{
			setAntDirection(EAST);
		}

		else
		{
			setAntDirection(WEST);
		}
	}

	if (currentDirection == EAST)
	{
		if (currentColor == WHITE)
		{
			setAntDirection(SOUTH);
		}

		else
		{
			setAntDirection(NORTH);
		}
	}

	if (currentDirection == SOUTH)
	{
		if (currentColor == WHITE)
		{
			setAntDirection(WEST);
		}

		else
		{
			setAntDirection(EAST);
		}
	}

	if (currentDirection == WEST)
	{
		if (currentColor == WHITE)
		{
			setAntDirection(NORTH);
		}

		else
		{
			setAntDirection(SOUTH);
		}
	}
}

/*********************************************************************  
** Function:  nextMoveValid()
** Description: Function that tests if the next move is on the grid.
**				It returns a boolean of true if the next move is on
**				the grid and false if it is not.
**  
*********************************************************************/
bool Ant::nextMoveValid()
{
	bool validMove = false;

	if (antDirection == NORTH)
	{
		if ((getYCoor() - 1) >= 0)
		{
			//setYCoor(getYCoor() - 1);
			validMove = true;
		}
	}

	if (antDirection == EAST)
	{
		if ((getXCoor() + 1) <= maxCols)
		{
			//setXCoor(getXCoor() + 1);
			validMove = true;
		}
	}


	if (antDirection == SOUTH)
	{
		if ((getYCoor() + 1) <= maxRows)
		{
			//setYCoor(getYCoor() + 1);
			validMove = true;
		}
	}


	if (antDirection == WEST)
	{
		if ((getXCoor() - 1) >= 0)
		{
			//setXCoor(getXCoor() - 1);
			validMove = true;
		}
	}

	return validMove;
}


/*********************************************************************  
** Function:  changeColor()
** Description: This function changes the color of sqColor variable.
**  
*********************************************************************/
void Ant::changeColor()
{

	if (sqColor == WHITE)
	{
		sqColor = BLACK;
	}

	else sqColor = WHITE;

}


/*********************************************************************  
** Function:  move()
** Description: moves the Ant one space forward in the direction
**				faced.
** 
*********************************************************************/
void Ant::move()
{
	if (antDirection == NORTH)
	{
		setYCoor(getYCoor() - 1);
	}


	if (antDirection == EAST)
	{
		setXCoor(getXCoor() + 1);
	}


	if (antDirection == SOUTH)
	{
		setYCoor(getYCoor() + 1);
	}


	if (antDirection == WEST)
	{
		setXCoor(getXCoor() - 1);
	}

}








