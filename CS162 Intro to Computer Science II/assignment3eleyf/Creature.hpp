/*********************************************************************  
** Program Filename:  Creature.hpp
** Author:  Frederick Eley  
** Date:  11/1/16
** Description:  Creature Class Header. 
*********************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

enum CreatureType { VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRY};
#include "feUtils.hpp"
#include <iostream>

class Creature
{
protected:
    int     armor,
            strength,
            lives;

    CreatureType   typeOfCreature;

    

public:
    virtual int     attack() = 0;
    virtual int 	defense() = 0;
    void 			setArmor(int a);
    void            setStrength(int s);
    void 			setLives(int l);
    void 			setTypeOfCreature(CreatureType t);
    int 			getArmor() const;
    int             getStrength() const;   
    int 			getLives() const;   
    CreatureType 	getTypeOfCreature() const;

};

#endif