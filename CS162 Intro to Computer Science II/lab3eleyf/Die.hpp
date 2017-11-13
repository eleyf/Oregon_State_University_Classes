/*********************************************************************  
** Program Filename:  Die.hpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  Die Class Header. 
*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <cstdlib>
#include <ctime>
#include "feUtils.hpp"


class Die
{
protected:
    int  sides;

public:
    Die();
    Die(int sides);
    void setSides(int sides);
    int getSides() const;
    int roll() const;
};

#endif