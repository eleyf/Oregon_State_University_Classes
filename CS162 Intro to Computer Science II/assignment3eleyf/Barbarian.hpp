/*********************************************************************  
** Program Filename:  Barbarian.hpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  Barbarian Class Header. 
*********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"


class Barbarian : public Creature
{
private:
	

public:
	Barbarian();
    virtual int 	attack();
    virtual int 	defense();
};

#endif