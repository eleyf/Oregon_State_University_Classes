/*********************************************************************  
** Program Filename:  Vampire.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Vampire Class Header. 
*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"


class Vampire : public Creature
{
private:
	

public:
	Vampire();
    virtual int 	attack();
    virtual int 	defense();
};

#endif