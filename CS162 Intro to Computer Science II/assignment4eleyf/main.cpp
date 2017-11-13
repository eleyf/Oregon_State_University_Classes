/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/20/16
** Description: This is the main program for Assignment 4. It uses
**				an abstact class Creature as a parent class to 
**				create polymorphic characters that battle one another.
**				It uses a Queue structure to implement two lineups and
**				a Stack structure to implement a list of defeated
**				fighters.
**
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>


#include "World.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	World w1;
	Queue p1Lineup;
	Queue p2Lineup;
	Stack loserStack;
	
	int gameChoice,
		numOfFighters,
		roundWinner,
		p1Score = 0,
		p2Score = 0,
		roundCounter = 1;

	Creature *  fighter1;
	Creature *  fighter2;




	// Create Lineups

	std::cout << std::endl << "How many fighters does each player start with? ";
	numOfFighters = getInt();
	while (numOfFighters < 1)
	{
		std::cout << std::endl;
		std::cout << "That is not a valid value." << std::endl;
		std::cout << "The value must be a positive integer.";
		std::cout << std::endl;
		std::cout << "How many fighters does each player start with?";
		numOfFighters = getInt();
	}

	std::cout << std::endl << "CREATE THE LINEUP FOR PLAYER 1." << std::endl;
	for (int i = 0; i < numOfFighters; i++)
	{
		w1.createPlayer(0, i + 1);
		p1Lineup.push(w1.getPlayer()[0]);
	}
	std::cout << std::endl << std::endl;

	std::cout << std::endl << "CREATE THE LINEUP FOR PLAYER 2." << std::endl;
	for (int i = 0; i < numOfFighters; i++)
	{
		w1.createPlayer(1, i + 1);
		p2Lineup.push(w1.getPlayer()[1]);
	}
	std::cout << std::endl << std::endl;




	// Get fighters from queues and have them fight

	fighter1 = p1Lineup.pop();
	fighter2 = p2Lineup.pop();

	while (fighter1 && fighter2) // if a queue is empty will not enter loop
	{
		// set fighters and have them fight
		w1.setPlayer(fighter1, 0);
		w1.setPlayer(fighter2, 1);
		roundWinner = w1.war();

		std::cout << std::endl;
		std::cout << "Round " << roundCounter;
		std::cout << ": Player 1 " << fighter1->getTypeOfCreature();
		std::cout << " VS. Player 2 " << fighter2->getTypeOfCreature() << ", ";
		std::cout << std::endl;

		// heal winner and move back into queue
		// move loser to stack, and update score
		if (roundWinner == 1)
		{
			fighter1->heal();
			p1Lineup.push(fighter1);
			loserStack.push(fighter2);
			p1Score++;
			std::cout << fighter1->getTypeOfCreature() << " won!";
			std::cout << std::endl;
		}
		else
		{
			fighter2->heal();
			p2Lineup.push(fighter2);
			loserStack.push(fighter1);
			p2Score++;
			std::cout << fighter2->getTypeOfCreature() << " won!";
			std::cout << std::endl;
		}

		std::cout << std::endl << "Player 1 Lineup:" << std::endl;
		p1Lineup.displayQueue();

		std::cout << std::endl << "Player 2 Lineup:" << std::endl;
		p2Lineup.displayQueue();

		std::cout << std::endl << "Defeated List:" << std::endl;
		loserStack.displayStack();

		std::cout << "Player 1 score: " << p1Score << std::endl;
		std::cout << "Player 2 score: " << p2Score << std::endl;
		std::cout << std::endl;

		roundCounter++;

		fighter1 = p1Lineup.pop();
		fighter2 = p2Lineup.pop();

	}

	// display winner and defeated list

	std::cout << std::endl << std::endl;
	std::cout << "The final score is:" << std::endl;
	std::cout << "Player 1 score: " << p1Score << std::endl;
	std::cout << "Player 2 score: " << p2Score << std::endl;
	std::cout << std::endl;

	if (p1Score > p2Score)
	{
		std::cout << std::endl << "The winner is Player 1." << std::endl;
	}

	else if (p1Score < p2Score)
	{
		std::cout << std::endl << "The winner is Player 2." << std::endl;
	}

	else
	{
		std::cout << std::endl << "The game is a tie." << std::endl;
	}

	
	std::cout << std::endl << "The list of defeated oppenents is:" << std::endl;
	loserStack.displayStack();
	std::cout << std::endl;

	std::cout << std::endl << "Thanks for playing." << std::endl;
	std::cout << std::endl;

	return 0;
}
