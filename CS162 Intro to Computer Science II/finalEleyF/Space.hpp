/*********************************************************************  
** Program Filename:  Space.hpp
** Author:  Frederick Eley  
** Date:  12/5/16
** Description:  Space Class Header. 
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include "feUtils.hpp"
#include <iostream>
#include <string>

class Space
{
protected:
    Space * pRight = NULL;
    Space * pLeft = NULL;
    Space * pTop = NULL;
    Space * pBottom = NULL;

    std::string nameOfSpace;

public:
    virtual void    printDesc() = 0;
    virtual bool    getSpaceState() = 0;
    virtual void 	specialAction() = 0;

    void            setPRight(Space & r);
    void            setPLeft(Space & l);
    void            setPTop(Space & t);
    void            setPBottom(Space & b);
    void 			setNameOfSpace(std::string n);
    Space *         getPRight() const;  
    Space *         getPLeft() const;  
    Space *         getPTop() const;  
    Space *			getPBottom() const;
    std::string     getNameOfSpace() const; 
};

#endif