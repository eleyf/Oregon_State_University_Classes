/*********************************************************************  
** Program Filename:  Roof.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Roof Class Header. 
*********************************************************************/

#ifndef ROOF_HPP
#define ROOF_HPP

#include "Space.hpp"


class Roof : public Space
{
private:
	bool keyOnRoof;
	
public:
	Roof(std::string n);
	~Roof();
    virtual void    printDesc();
	virtual bool    getSpaceState();
    virtual void 	specialAction();
};

#endif