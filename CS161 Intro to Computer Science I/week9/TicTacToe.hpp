/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 9
**			This is the header file for
**			the TicTacToe class.
**
**********************************************/

#ifndef TicTacToe_HPP
#define TicTacToe_HPP


#include "Board.hpp"


// TicTacToe class declaration


class TicTacToe
{
private:
	Board	boardGame;
	char	player;

public:
	TicTacToe(char firstPlayerIn);
	void play();
};

#endif