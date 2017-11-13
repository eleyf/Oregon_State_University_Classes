/********************************************************************
**
**	Author: Frederick Eley
**	ONID:	eleyf
**	Date:	1/18/2016
**	Description: Week 3 Assignment 3.c
**
**				This program prompts the user for an interger
**				to be guessed by the player. The program loops
**				until a correct guess is made. If the guess is
**				wrong, it tells the player if it's too high or 
**				too low. Once a correct guess is made the number
**				of guesses made is displayed.
**
********************************************************************/

#include <iostream>

using namespace std;

int main()
{
	int	  correctNumber,
		  playerGuess,
		  numberOfTries = 1;  	 // Intitialize the number of guesses to one
	bool  correctGuess = false;  // Initialize boolean value to false

	// Prompt user for number to be guessed
	cout << "Enter the number for the player to guess." << endl;
	cin  >> correctNumber;
	cin.ignore();
	cout << "Enter your guess." << endl;

	// Do-while loop because we want to execute at least once
	do
	{
		// Read player's guess
		cin >> playerGuess;
		cin.ignore();

		// If guess is correct
		if (playerGuess == correctNumber)
		{
			correctGuess = true;
		}
		
		// If guess is incorrect
		else
		{
			//Increment counter because we will loop
			numberOfTries++;
			
			// Test if number is too high
			if (playerGuess > correctNumber)
			{
				// Prompt user to enter another guess
				cout << "Too high - try again." << endl;
			}
			
			// Only condition left is lower than
			else
			{
				// Prompt user to enter another guess
				cout << "Too low - try again." << endl;
			}	
		}

	} while (!correctGuess);

	// Print number of tries
	cout << "You guessed it in " << numberOfTries << " tries.";
	cout << endl << endl; 

	return 0;
}