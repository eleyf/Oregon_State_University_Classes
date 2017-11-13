/*********************************************************************  
** Program Filename:  Harry.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Harry Class Header. 
*********************************************************************/

#ifndef HARRY_HPP
#define HARRY_HPP

#include "Creature.hpp"


class Harry : public Creature
{
private:
	

public:
	Harry();
    virtual int 	attack();
    virtual int 	defense();
};

#endif