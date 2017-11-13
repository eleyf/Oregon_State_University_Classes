/*********************************************************************  
** Program Filename:  Game.cpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  These are the function definitions of the Game
**				 class.
** Input:	The default constructor sets all values to zero.
**
*********************************************************************/

#include "Game.hpp"


/* constructors */
Game::Game()
{
	setSides1(0);
    setSides2(0);
    setRounds(0);
    setDie1Wins(0);
    setDie2Wins(0);
    setTies(0);
    setDieType1(REGULAR);
    setDieType2(REGULAR);
}


/* setters and getters */
void Game::setSides1(int sides1)
{
	this->sides1 = sides1;
}

void Game::setSides2(int sides2)
{
	this->sides2 = sides2;
}

void Game::setRounds(int rounds)
{
	this->rounds = rounds;
}

void Game::setDie1Wins(int die1Wins)
{
	this->die1Wins = die1Wins;
}

void Game::setDie2Wins(int die2Wins)
{
	this->die2Wins = die2Wins;
}

void Game::setTies(int ties)
{
	this->ties = ties;
}

void Game::setDieType1(TypeOfDie dieType1)
{
	this->dieType1 = dieType1;
}

void Game::setDieType2(TypeOfDie dieType2)
{
	this->dieType2 = dieType2;
}

int Game::getSides1() const
{
	return sides1;
}

int Game::getSides2() const
{
	return sides2;
}

int Game::getRounds() const
{
	return rounds;
}

int Game::getDie1Wins() const
{
	return die1Wins;
}

int Game::getDie2Wins() const
{
	return die2Wins;
}

int Game::getTies() const
{
	return ties;
}

TypeOfDie Game::getDieType1() const
{
	return dieType1;
}

TypeOfDie Game::getDieType2() const
{
	return dieType2;
}


/*********************************************************************  
** Function:  inputInfo()
** Description: Function that prompts the user for the number of
**				rounds, the size and type of the dice, and sets
**				those parameters to the two dice.
**  
*********************************************************************/
void Game::inputInfo()
{
	std::cout << std::endl;
	std::cout << "This is a game of war using two dice: " << std::endl;
	std::cout << std::endl;

	/* rounds info */
	std::cout << "Enter the number of rounds you would like to play: ";
	setRounds(getInt());
	std::cout << std::endl;

	/* die1 info */
	std::cout << std::endl;
	std::cout << "Enter the number of sides for the first player's die: ";
	setSides1(getInt());
	std::cout << std::endl;
	std::cout << "Would you this die to be regular or loaded?" << std::endl;
	std::cout << "Enter 1 for regular or 2 for loaded: ";
	tempType = getSwitchChoice(2);
	if (tempType == 1)
	{
		setDieType1(REGULAR);
	}
	else
	{
		setDieType1(LOADED);
	}

	/* die2 info */
	std::cout << std::endl;
	std::cout << "Enter the number of sides for the second player's die: ";
	setSides2(getInt());
	std::cout << std::endl;
	std::cout << "Would you this die to be regular or loaded?" << std::endl;
	std::cout << "Enter 1 for regular or 2 for loaded: ";
	tempType = getSwitchChoice(2);
	if (tempType == 1)
	{
		setDieType2(REGULAR);
	}
	else
	{
		setDieType2(LOADED);
	}

}

/*********************************************************************  
** Function:  play()
** Description: Function rolls the dice for the determined number
**				of rounds and keeps track of the win totals.
**  
*********************************************************************/
void Game::play()
{
	/* both dice are regular */
	if (dieType1 == REGULAR && dieType2 == REGULAR)
	{
		/* set correct number of sides for dice */
		regDie1.setSides(sides1);
		regDie2.setSides(sides2);

		for(int i = 0; i < rounds; i++)
		{
			int die1Val = regDie1.roll(),
				die2Val = regDie2.roll();

			if(die1Val < die2Val)
			{
				die2Wins++;
			}
			else if(die1Val > die2Val)
			{
				die1Wins++;
			}
			else
			{
				ties++;
			}
		}
	}


	/* die1 is regular and die2 is loaded */
	if (dieType1 == REGULAR && dieType2 == LOADED)
	{
		/* set correct number of sides for dice */
		regDie1.setSides(sides1);
		loadedDie2.setSides(sides2);

		for(int i = 0; i < rounds; i++)
		{
			int die1Val = regDie1.roll(),
				die2Val = loadedDie2.roll();

			if(die1Val < die2Val)
			{
				die2Wins++;
			}
			else if(die1Val > die2Val)
			{
				die1Wins++;
			}
			else
			{
				ties++;
			}
		}
	}

	/* die1 is loaded and die2 is regular */
	if (dieType1 == LOADED && dieType2 == REGULAR)
	{
		/* set correct number of sides for dice */
		loadedDie1.setSides(sides1);
		regDie2.setSides(sides2);

		for(int i = 0; i < rounds; i++)
		{
			int die1Val = loadedDie1.roll(),
				die2Val = regDie2.roll();

			if(die1Val < die2Val)
			{
				die2Wins++;
			}
			else if(die1Val > die2Val)
			{
				die1Wins++;
			}
			else
			{
				ties++;
			}
		}
	}

	/* both dice are loaded */
	if (dieType1 == LOADED && dieType2 == LOADED)
	{
		/* set correct number of sides for dice */
		loadedDie1.setSides(sides1);
		loadedDie2.setSides(sides2);

		for(int i = 0; i < rounds; i++)
		{
			int die1Val = loadedDie1.roll(),
				die2Val = loadedDie2.roll();

			if(die1Val < die2Val)
			{
				die2Wins++;
			}
			else if(die1Val > die2Val)
			{
				die1Wins++;
			}
			else
			{
				ties++;
			}
		}
	}

}


/*********************************************************************  
** Function:  results()
** Description: Function that displays the size and type of each die,
**				the number of wins of each player and the overall
**				winner.
**  
*********************************************************************/
void Game::results() const
{
	const std::string typeName[] = {"regular", "loaded"};

	std::cout << std::endl;
	std::cout << "Player 1 used a " << typeName[dieType1] << " die with " << sides1 <<" sides and has ";
	std::cout << die1Wins << " wins." << std::endl;
	std::cout << "Player 2 used a " << typeName[dieType2] << " die with " << sides2 <<" sides and has ";
	std::cout << die2Wins << " wins." << std::endl;
	std::cout << "There were " << ties << " ties." << std::endl;

	if(die1Wins > die2Wins)
	{
		std::cout << "Player 1 is the winner." << std::endl;
	}
	else if(die1Wins < die2Wins)
	{
		std::cout << "Player 2 is the winner." << std::endl;
	}
	else
	{
		std::cout << "The contest is a tie." << std::endl;
	}
}






