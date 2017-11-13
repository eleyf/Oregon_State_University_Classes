/*********************************************************************  
** Program Filename:  Doodlebug.hpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  Doodlebug Class Header. 
*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include <iostream>
#include "Critter.hpp"


class Doodlebug : public Critter
{
private:
	

public:
	Doodlebug();
	Doodlebug(int posX, int posY);
    virtual void 	move(Direction directionToMove); 
};

#endif