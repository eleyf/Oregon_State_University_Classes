/*********************************************************************  
** Program Filename:  Item.cpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description:  These are the function definitions of the Item
**				 class.
**
*********************************************************************/

#include "Item.hpp"


/* constructors */
Item::Item()
{
	this->itemName = " ";
	this->unit = " ";
	this->quantity = 0;
	this->unitPrice = 0.0;
}


Item::Item(std::string n, std::string u, int q, double p)
{
	this->itemName = n;
	this->unit = u;
	this->quantity = q;
	this->unitPrice = p;
}


/* setters and getters */
void Item::setItemName(std::string n)
{
	itemName = n;
}

void Item::setUnit(std::string u)
{
	unit = u;
}

void Item::setQuantity(int q)
{
	quantity = q;
}

void Item::setUnitPrice(double p)
{
	unitPrice = p;
}

int Item::getQuantity()
{
	return quantity;
}


/*********************************************************************  
** Function:  extendedPrice();
** Description: Function that returns the total price for the number
**				of items wanted.
**  
*********************************************************************/
double Item::extendedPrice()
{
	return quantity * unitPrice;
}


/*********************************************************************  
** Function:  printItem();
** Description: Function that displays the name, unit of sale,
**				number need, unit price, and extended price of an item.
**
**  
*********************************************************************/
void Item::printItem()
{
	std::cout << std::endl;
	std::cout << "Item: " << itemName << std::endl;
	std::cout << "Unit of Sale: " << unit << std::endl;
	std::cout << "Number Needed: " << quantity << std::endl;
	std::cout << "Unit Price: $" << std::fixed << std::setprecision(2) << unitPrice << std::endl;
	std::cout << "Extended Price: $" << std::fixed << std::setprecision(2) << this->extendedPrice() << std::endl;
	std::cout << std::endl;
}

/*********************************************************************  
** Function:  Overloded operator== 
** Description: Function that overloads the operator ==
**
*********************************************************************/
bool operator== (Item a, Item b)
{
	if (	(a.itemName == b.itemName)
		&&	(a.unit == b.unit)
		&&	(a.unitPrice == b.unitPrice)
		)
	{
		return true;
	}
	else 
	{
		return false;
	}
}

