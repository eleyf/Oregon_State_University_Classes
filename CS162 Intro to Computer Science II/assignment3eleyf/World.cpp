/*********************************************************************  
** Program Filename:  World.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  These are the function definitions of the World
**				 class.
**
**
*********************************************************************/

#include "World.hpp"


/* constructors */
World::World()
{
	// create array to hold players
	currentAttacker = 0;
	player = new Creature *[2];
	for (int i = 0; i < 2; i++)
		player[i] = NULL;

}

World::~World()
{
	for(int i = 0; i < 2; i++)
	{
		delete [] player[i];
	}
	delete [] player;
}



Creature ** World::getPlayer()
{
	return player;
}

/*********************************************************************  
** Function:  createVampire()
** Description: Function that creates a new Vampire object.
**
**  
*********************************************************************/
void World::createVampire(int i)
{
	player[i] = new Vampire();
}

/*********************************************************************  
** Function:  createBarbarian()
** Description: Function that creates a new Barbarian object.
**
**  
*********************************************************************/
void World::createBarbarian(int i)
{
	player[i] = new Barbarian();
}

/*********************************************************************  
** Function:  createBluemen()
** Description: Function that creates a new Bluemen object.
**
**  
*********************************************************************/
void World::createBluemen(int i)
{
	player[i] = new Bluemen();
}

/*********************************************************************  
** Function:  createMedusa()
** Description: Function that creates a new Medusa object.
**
**  
*********************************************************************/
void World::createMedusa(int i)
{
	player[i] = new Medusa();
}

/*********************************************************************  
** Function:  createHarry()
** Description: Function that creates a new Harry object.
**
**  
*********************************************************************/
void World::createHarry(int i)
{
	player[i] = new Harry();
}


/********************************************************************  
** Function:  battle()
** Description: Function that calculates damage done by a battle.
**  
********************************************************************/
int World::battle(int att, int def)
{
	int attackPoints,
		defendPoints;
	
	attackPoints = player[att]->attack();
	defendPoints = player[def]->defense();

	// if Medusa glare attack is detected return 1000 as flag
	if (attackPoints == -1)
	{
		return 1000;
	}
	// if Vampire charm flag is detected no damage is done
	// use flag of -1000
	else if (defendPoints == -1)
	{
		return -1000;
	}
	// if defend is greater than attack no damage is done
	else if (defendPoints > attackPoints)
	{
		return -1000;
	}
	else
	{
		return attackPoints - defendPoints;
	}

}

/********************************************************************  
** Function:  updateDefender()
** Description: Function that updates damage done to the defender.
**  
********************************************************************/
void World::updateDefender(int def, int dam)
{
	// if damage is greater than armor 
	if (dam > player[def]->getArmor())
	{
		player[def]->setStrength(player[def]->getStrength() - (dam - player[def]->getArmor()));
	}

	// if strength is zero or less loose a life
	if (player[def]->getStrength() <= 0)
	{
		player[def]->setLives(player[def]->getLives() - 1);
	}
	
	// if player is harry and he has a life left and he has negative points regenate strength
	if (player[def]->getTypeOfCreature() == HARRY && player[def]->getStrength() <= 0 && player[def]->getLives() == 1)
	{
		player[def]->setStrength(20);
	}
}


/********************************************************************  
** Function:  swapAttacker()
** Description: Function that swaps the attacker.
**  
********************************************************************/
void World::swapAttacker()
{
	if (currentAttacker == 0)
	{
		currentAttacker = 1;
		currentDefender = 0;
	}
	else
	{
		currentAttacker = 0;
		currentDefender = 1;
	}
}

/********************************************************************  
** Function:  createPlayer()
** Description: Function that creates a player.
**  
********************************************************************/
void World::createPlayer(int p)
{
	int characterChoice;

	// Display menu
	std::cout << std::endl;
	std::cout << "   Choose Player " << p + 1 << " Character" << std::endl << std::endl;
	std::cout << "1. Vampire" << std::endl;
	std::cout << "2. Barbarian" << std::endl;
	std::cout << "3. Bluemen" << std::endl;
	std::cout << "4. Medusa" << std::endl;
	std::cout << "5. Harry Potter" << std::endl;

	std::cout << std::endl << "Enter the choice of the character for player 1 you want to utilize (1 - 5)";
	std::cout << std::endl;

	// Validate selection
	characterChoice = getSwitchChoice(5);

	//enter switch to create character
		switch(characterChoice)
		{
			// create Vampire
			case 1:
					createVampire(p);
					break;

			// create Barbarian
			case 2:
					createBarbarian(p);
					break;

			// create Bluemen
			case 3:
					createBluemen(p);
					break;

			// create Medusa
			case 4:
					createMedusa(p);
					break;

			// create Harry
			case 5:
					createHarry(p);
					break;
		}
}


/********************************************************************  
** Function:  war()
** Description: Function that battles two players until one dies.
**  
********************************************************************/
void World::war()
{
	while(player[0]->getLives() != 0 && player[1]->getLives() != 0)
	{
		int damage;
		damage = battle(currentAttacker, currentDefender);
		updateDefender(currentDefender, damage);
		swapAttacker();
	}

	if (player[1]->getLives() <= 0)
	{
		std::cout << "The winner is Player 1 who has " << player[0]->getStrength();
		std::cout <<  " strength points remaining." << std::endl;
	}
	else
	{
		std::cout << "The winner is Player 2 who has " << player[1]->getStrength();
		std::cout <<  " strength points remaining." << std::endl;
	}
}

/********************************************************************  
** Function:  play()
** Description: Function that plays the game.
**  
********************************************************************/
void World::play()
{
	createPlayer(0);
	createPlayer(1);
	war();
}
























