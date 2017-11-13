/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/22/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 8
**			This is the header file for
**			the ShoppingCart class.
**
**********************************************/

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#define ARRAYSIZE 100
#include "Item.hpp"
#include <cstdlib>
using namespace std;

// ShoppingCart class declaration

class ShoppingCart
{
private:
	Item * itemPtr[ARRAYSIZE];
	int	arrayEnd;

public:
	ShoppingCart();
	void addItem(Item *itemPtrIn);
	double totalPrice();
};

#endif