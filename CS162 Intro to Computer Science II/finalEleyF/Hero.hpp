/*********************************************************************  
** Program Filename:  Hero.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Hero Class Header. 
*********************************************************************/

#ifndef HERO_HPP
#define HERO_HPP

#include "feUtils.hpp"
#include <iostream>
#include <string>

class Hero
{
private:
    std::string pocket[3];
    int pocketIndex = 0;

public:
    Hero();
    ~Hero();
    void putInPocket(std::string n);
    void displayPocket();
    bool searchPocket(std::string n);
};

#endif