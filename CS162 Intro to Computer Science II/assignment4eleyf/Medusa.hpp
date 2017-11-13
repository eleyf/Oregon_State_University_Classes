/*********************************************************************  
** Program Filename:  Medusa.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Medusa Class Header. 
*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"


class Medusa : public Creature
{
private:
	

public:
	Medusa();
    virtual int 	attack();
    virtual int 	defense();
};

#endif