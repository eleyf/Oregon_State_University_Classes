/*********************************************************************  
** Program Filename:  Ant.hpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  Ant Class Header. 
*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include "Critter.hpp"


class Ant : public Critter
{
private:
	

public:
	Ant();
	Ant(int posX, int posY);
    virtual void 	move(Direction directionToMove);
};

#endif