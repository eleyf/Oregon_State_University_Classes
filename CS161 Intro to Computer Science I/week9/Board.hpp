/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 9
**			This is the header file for
**			the Board class.
**
**********************************************/

#ifndef Board_HPP
#define Board_HPP

#include <iostream>
using namespace std;
enum State { X_WON, O_WON, DRAW, UNFINISHED };

// Board class declaration


class Board
{
private:
	char	moveArray[3][3];

public:
	Board();
	bool	makeMove(int rowIn, int colIn, char playerIn);
	State 	gameState();
	void	print();
};

#endif