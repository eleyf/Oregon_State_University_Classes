/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description: This is the main program for Lab3. It
**				plays a game of war using two dice. The user chooses
**				the number of sides for each die and if the die is
**				loaded or regular.
** Input:	Number of rounds to play. Number of sides of each die.
**			Type of die, regular or loaded.
** Output:	The size and type of die, number of wins of each player 
**			and the overall winner. 
*********************************************************************/

#include <ctime>
#include <cstdlib>
#include "Game.hpp"


int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	Game thisGame;

	thisGame.inputInfo();
	thisGame.play();
	thisGame.results();

	return 0;
}