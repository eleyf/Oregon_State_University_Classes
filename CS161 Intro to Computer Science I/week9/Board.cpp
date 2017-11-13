/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 9
**			These are the function definitions
**			for the Board class.
**
**********************************************/

#include "Board.hpp"

/*********************************************
**
**	Default constructor that that initializes 
**	a 3x3 array to being empty.
** 
**********************************************/
Board::Board()
{
	for (int row = 0; row < 3; row++)
	{	
		for (int col = 0; col < 3; col++)
		{
			moveArray[row][col] = '.';
		}
	}
}


/*********************************************
**
**				makeMove
**
**	Class function that takes as parameters 
**	the x and y coordinates of the move and
**	which player's turn it is. If that location
**	is unoccupied, the move is recorded and
**	true is returned. If that location is
**	already occupied, false is returned.
** 
**********************************************/
bool Board::makeMove(int rowIn, int colIn, char playerIn)
{
	bool moveMade = true;

	if (moveArray[rowIn][colIn] == '.')
	{
		moveArray[rowIn][colIn] = playerIn;
	}
	else
	{
		moveMade = false;
	}
	return moveMade;
}

/*********************************************
**
**				gameState
**
**	Class function that takes no parameters,
**	tests the state of the game, and returns 
**	an enum state of X_WON, O_WON, DRAW, or
**	UNFINISHED.
** 
**********************************************/
State Board::gameState()
{
	// default state set to DRAW
	// so no test needed for DRAW
	State stateOfGame = DRAW;

	// test if X won
		// test X for row winner
		for (int row = 0; row < 3; row++)
		{
			if ( moveArray[row][0] == 'x'
				 && moveArray[row][1] == 'x'
				 && moveArray[row][2] == 'x')
			{
				stateOfGame = X_WON;
			}

		}

		// test X for column winner
		for (int col = 0; col < 3; col++)
		{
			if (moveArray[0][col] == 'x'
				&& moveArray[1][col] == 'x'
				&& moveArray[2][col] == 'x')
			{
				stateOfGame = X_WON;
			}

		}

		// test X for L-R diagonal winner
		 if ( moveArray[0][0] == 'x'
		 	  && moveArray[1][1] == 'x'
		 	  && moveArray[2][2] == 'x')
		 {

		 	stateOfGame = X_WON;
		 }

		 // test X for R-L diagonal winner
		 if ( moveArray[0][2] == 'x'
		 	  && moveArray[1][1] == 'x'
		 	  && moveArray[2][0] == 'x')
		 {

		 	stateOfGame = X_WON;
		 }


	// test if O won
		// test O for row winner
		for (int row = 0; row < 3; row++)
		{
			if ( moveArray[row][0] == 'o'
				 && moveArray[row][1] == 'o'
				 && moveArray[row][2] == 'o')
			{
				stateOfGame = O_WON;
			}

		}

		// test O for column winner
		for (int col = 0; col < 3; col++)
		{
			if (moveArray[0][col] == 'o'
				&& moveArray[1][col] == 'o'
				&& moveArray[2][col] == 'o')
			{
				stateOfGame = O_WON;
			}

		}

		// test O for L-R diagonal winner
		 if ( moveArray[0][0] == 'o'
		 	  && moveArray[1][1] == 'o'
		 	  && moveArray[2][2] == 'o')
		 {

		 	stateOfGame = O_WON;
		 }

		// test O for R-L diagonal winner
		if ( moveArray[0][2] == 'o'
		 	  && moveArray[1][1] == 'o'
		 	  && moveArray[2][0] == 'o')
		 {

		 	stateOfGame = O_WON;
		 }

	// test for unfinished
		// if X nor O has won yet
		// test to see if any location is still empty
		if (stateOfGame == DRAW)
		for (int row = 0; row < 3; row++)
		{	
			for (int col = 0; col < 3; col++)
			{
				if ( moveArray[row][col] == '.')
					{
						stateOfGame = UNFINISHED;
					}
			}
		} 

	return stateOfGame;

}

/*********************************************
**
**				print
**
**	Class function that takes no parameters and 
**	prints out the current board to the screen.
** 
**********************************************/
void Board::print()
{
	// print header row
	cout << endl;
	cout << "  " << "0 " << "1 " << "2 " << endl;
	cout << endl;
	// print the contents of each row
	for (int row = 0; row < 3; row++)
	{	
		cout << row << " ";
		for (int col = 0; col < 3; col++)
		{
			cout << moveArray[row][col] << " ";
		}
		cout << endl << endl;
	}
}