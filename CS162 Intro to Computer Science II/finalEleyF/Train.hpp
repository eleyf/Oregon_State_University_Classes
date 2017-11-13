/*********************************************************************  
** Program Filename:  Train.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Train Class Header. 
*********************************************************************/

#ifndef TRAIN_HPP
#define TRAIN_HPP


#include <iostream>
#include <string>
#include "Engine.hpp"
#include "Cabin.hpp"
#include "Hero.hpp"
#include "Roof.hpp"
#include "Caboose.hpp"
#include "feUtils.hpp"


class Train
{
private:
	Space * currentSpace = NULL;

	Engine 	eng1("engine room");
	Cabin  	cab1("front cabin");
	Cabin  	cab2("rear cabin");
	Roof   	rf1("front roof");
	Roof   	rf2("rear roof");
	Caboose boos1("caboose");
	Hero   hero1;
	int moveChoice,
		moveCounter;

	
public:
	Train();
	~Train();
	void play();
};

#endif