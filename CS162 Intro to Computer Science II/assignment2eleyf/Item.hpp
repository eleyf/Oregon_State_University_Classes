/*********************************************************************  
** Program Filename:  Item.hpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description:  Item Class Header. 
*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "feUtils.hpp"


class Item
{
private:
    std::string	itemName,
    			unit;
    int			quantity;
    double		unitPrice;

public:
    Item();
    Item(std::string n, std::string u, int q, double p);
    void	setItemName(std::string n);
    void	setUnit(std::string u);
    void	setQuantity(int q);
    void	setUnitPrice(double p);
    int		getQuantity();
    double	extendedPrice();
    void 	printItem();
    friend bool	operator== (Item a, Item b);
};

#endif