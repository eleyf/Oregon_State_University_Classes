/*********************************************************************  
** Program Filename:  Bluemen.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Bluemen Class Header. 
*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"


class Bluemen : public Creature
{
private:
	

public:
	Bluemen();
    virtual int 	attack();
    virtual int 	defense();
};

#endif