/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 9
**			These are the function definitions
**			for the TicTacToe class and a main
**			method that asks the user which
**			player should go first, creates a
**			new TicTacToe object and starts the
**			game.
**
**********************************************/


#include "TicTacToe.hpp"


int main()
{

	char whoIsFirst;

	// prompt user for which player will go first
	cout << "Which player has the first move: x or o ?" << endl;
	cin  >> whoIsFirst;

	// create TicTacToe object and start the game
	TicTacToe game(whoIsFirst);
	game.play();


	return 0;
}

// TicTacToe function definitions

/*********************************************
**
**	Constructor that takes a char parameter 
**	that specifies whether 'x' or 'o' should
**	have the first move.
** 
**********************************************/
TicTacToe::TicTacToe(char firstPlayerIn)
{
	player = firstPlayerIn;
}

/*********************************************
**
**				play
**
**	Class function that takes no parameters 
**	and starts the game. The function keeps
**	looping, asking the correct player for
**	their move and sending it to the board
**	until someone has won or it's a draw.
**	After there is a winner or a draw the
**	outcome is printed.
**
**********************************************/
void TicTacToe::play()
{
	int	rowMove, colMove;

	cout << "Player " << player << " is first" << endl;
	
	// Create and print board
	Board boardGame;
	boardGame.print();

	// play game in do/while loop until state is other than UNFINISHED
	do
	{
		cout << "Player " << player << ": please enter your move." << endl;
		cin >>	rowMove >> colMove;
		
		// make move, if unable makeMove returns false 
		// and prompts same user for another move
		while (!boardGame.makeMove(rowMove, colMove, player))
		{
			cout << endl;
			cout << "That square is already taken." << endl;
			boardGame.print();
			cout << "Player " << player << ": please enter your move." << endl;
			cin >>	rowMove >> colMove;
		}
		// print board after move has been made
		boardGame.print();
		// switch players
		if (player == 'x')
		{
			player = 'o';
		}
		else player = 'x';
	}
	// test if state is UNFINISHED, back to DO if so
	while (boardGame.gameState() == UNFINISHED);

	
	// print results of game
		// print player x winner
		if (boardGame.gameState() == X_WON)
		{
			cout << "Player x is the winner." << endl;
			cout << endl;
		}

		// print player o winner
		if (boardGame.gameState() == O_WON)
		{
			cout << "Player o is the winner." << endl;
			cout << endl;
		}

		// print draw game
		if (boardGame.gameState() == DRAW)
		{
			cout << "The game is a draw." << endl;
			cout << endl;
		}

}