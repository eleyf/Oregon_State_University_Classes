/*********************************************************************  
** Program Filename:  Critter.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  These are the function definitions of the Critter
**				 class.
**
*********************************************************************/

#include "Critter.hpp"

/* setters and getters */
void Critter::setPositionX(int posX)
{
	this->positionX = posX;
}

void Critter::setPositionY(int posY)
{
	this->positionY = posY;
}

void Critter::setNumOfMoves(int n)
{
	this->numOfMoves = n;
}

void Critter::setTypeOfCritter(CritterType t)
{
	this->typeOfCritter = t;
}

int Critter::getPositionX() const
{
	return positionX;
}

int Critter::getPositionY() const
{
	return positionY;
}

int Critter::getNumOfMoves() const
{
	return numOfMoves;
}

CritterType Critter::getTypeOfCritter() const
{
	return typeOfCritter;
}


