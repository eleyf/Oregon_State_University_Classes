/*********************************************************************  
** Program Filename:  Caboose.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Caboose Class Header. 
*********************************************************************/

#ifndef CABOOSE_HPP
#define CABOOSE_HPP

#include "Space.hpp"


class Caboose : public Space
{
private:
	bool codeOnCaboose;
	
public:
	Caboose(std::string n);
	~Caboose();
    virtual void    printDesc();
	virtual bool    getSpaceState();
    virtual void 	specialAction();
};

#endif