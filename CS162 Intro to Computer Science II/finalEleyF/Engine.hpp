/*********************************************************************  
** Program Filename:  Engine.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Engine Class Header. 
*********************************************************************/

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "Space.hpp"


class Engine : public Space
{
private:
	bool bomb;
	
public:
	Engine(std::string n);
	~Engine();
    virtual void    printDesc();
    virtual bool    getSpaceState();
    virtual void 	specialAction();
};

#endif