/*********************************************************************  
** Program Filename:  Game.hpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  Game Class Header. 
*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "feUtils.hpp"
#include "Die.hpp"
#include "LoadedDie.hpp"

enum TypeOfDie{REGULAR, LOADED};


class Game
{
private:
    int  		sides1,
    			sides2,
    			rounds,
    			tempType,
    			die1Wins,
    			die2Wins,
    			ties;
    TypeOfDie	dieType1,
    			dieType2;
    Die         regDie1,
    			regDie2;
    LoadedDie	loadedDie1,
    			loadedDie2;


public:
    Game();
    void 		setSides1(int sides1);
    void 		setSides2(int sides2);
    void 		setRounds(int rounds);
    void 		setDie1Wins(int die1Wins);
    void 		setDie2Wins(int die2Wins);
    void 		setTies(int ties);
    void 		setDieType1(TypeOfDie dieType1);
    void 		setDieType2(TypeOfDie dieType2);

    int 		getSides1() const;
    int 		getSides2() const;
	int 		getRounds() const;
	int 		getDie1Wins() const;
    int 		getDie2Wins() const;
	int 		getTies() const;
    TypeOfDie 	getDieType1() const;
    TypeOfDie 	getDieType2() const;

    void 		inputInfo();
    void		play();
    void		results() const;
};

#endif