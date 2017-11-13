/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/22/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 8
**			These are the function definitions
**			for the ShoppingCart class.
**
**********************************************/

#include "ShoppingCart.hpp"

/************************************************
**
**	Default constructor that initializes each
**	element of the array to NULL and initializes
**	arrayEnd to zero.
** 
************************************************/
ShoppingCart::ShoppingCart()
	{
		for (int i = 0; i < ARRAYSIZE; i++)
		{
			itemPtr[i] = NULL;
		}
		arrayEnd = 0;
	}

/*********************************************
**
**				addItem
**
**	Class function that takes as a parameter 
**	a pointer to a Item class object, adds
**	it to the ShoppingCart array, and updates
**	arrayEnd.
** 
**********************************************/
void ShoppingCart::addItem(Item *itemPtrIn)
	{
		itemPtr[arrayEnd] = itemPtrIn;
		arrayEnd ++;
	}

/*********************************************
**
**				totalPrice
**
**	Class function that returns the total cost
**	of all Items in the ShoppingCart array.
** 
**********************************************/
double ShoppingCart::totalPrice()
	{
		double total = 0;

		for (int i = 0; i < arrayEnd; i++)
		{
			total += itemPtr[i]->getPrice() * itemPtr[i]->getQuantity();
		}


		return total;
	}