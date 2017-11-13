/*********************************************************************  
** Program Filename:  Creature.cpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  These are the function definitions of the Creature
**				 class.
**
*********************************************************************/

#include "Creature.hpp"

/* setters and getters */
void Creature::setArmor(int a)
{
	armor = a;
}

void Creature::setStrength(int s)
{
	strength = s;
}
void Creature::setLives(int l)
{
	lives = l;
}

void Creature::setTypeOfCreature(CreatureType t)
{
	typeOfCreature = t;
}

int Creature::getArmor() const
{
	return armor;
}

int Creature::getStrength() const
{
	return strength;
}

int Creature::getLives() const
{
	return lives;
}

CreatureType Creature::getTypeOfCreature() const
{
	return typeOfCreature;
}

void Creature::heal()
{
	strength = strength * 1.25;
}

