/*********************************************************************  
** Program Filename:  World.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  World Class Header. 
*********************************************************************/

#ifndef WORLD_HPP
#define WORLD_HPP

#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "Bluemen.hpp"
#include "Medusa.hpp"
#include "Harry.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

class World
{
private:

	Creature **player;
	int currentAttacker,
		currentDefender;	

public:
	World();
	~World();
	Creature ** getPlayer();
	void	setPlayer(Creature * f, int p);
	void	createVampire(int i);
	void	createBarbarian(int i);
	void	createBluemen(int i);
	void	createMedusa(int i);
	void	createHarry(int i);
	int		battle(int att, int def);
	void	updateDefender(int def, int dam);
	void	swapAttacker();
	void	createPlayer(int p, int n);
	int		war();
	// void	play();

};

#endif