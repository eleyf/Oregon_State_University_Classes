/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/22/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 8
**			These are the function definitions
**			for the Item class.
**
**********************************************/

#include "Item.hpp"

/*********************************************
**
**	Default constructor that uses the set
**	methods to initialize name to "", price
**	to 0.0 and quantity to 0.
** 
**********************************************/
Item::Item()
	{
		setName("");
		setPrice(0.0);
		setQuantity(0);
	}

/*********************************************
**
**	Constructor that takes three parameters
**	name, price, and quantity and passes them
**	to the set methods to initialize them.
**
**********************************************/
Item::Item(string nameIn, double priceIn, int quantityIn)
	{
		setName(nameIn);
		setPrice(priceIn);
		setQuantity(quantityIn);
	}

// set name
void Item::setName(string nameIn)
	{
		name = nameIn;
	}

// set price
void Item::setPrice(double priceIn)
	{
		price = priceIn;
	}

// set quantity
void Item::setQuantity(int quantityIn)
	{
		quantity = quantityIn;
	}

// return name
string Item::getName()
	{
		return name;
	}

// return price
double Item::getPrice()
	{
		return price;
	}

// return quantity
int Item::getQuantity()
	{
		return quantity;
	}