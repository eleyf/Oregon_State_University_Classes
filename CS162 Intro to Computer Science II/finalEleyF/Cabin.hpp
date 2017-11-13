/*********************************************************************  
** Program Filename:  Cabin.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Cabin Class Header. 
*********************************************************************/

#ifndef CABIN_HPP
#define CABIN_HPP

#include "Space.hpp"


class Cabin : public Space
{
private:
	bool doorLocked;
	
public:
	Cabin(std::string n);
	~Cabin();
    virtual void    printDesc();
	virtual bool    getSpaceState();
    virtual void 	specialAction();
};

#endif