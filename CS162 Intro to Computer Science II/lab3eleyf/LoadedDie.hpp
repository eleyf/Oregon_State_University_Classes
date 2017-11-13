/*********************************************************************  
** Program Filename:  LoadedDie.hpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  LoadedDie Class Header. 
*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"


class LoadedDie : public Die
{
public:
    LoadedDie();
    LoadedDie(int sides);
    int roll() const;
};

#endif