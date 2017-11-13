/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/22/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 8
**			This is the header file for
**			the Item class.
**
**********************************************/

#ifndef Item_HPP
#define Item_HPP

#include <string>
using namespace std;

// Item class declaration

class Item
{
private:
	string	name;
	double	price;
	int		quantity;

public:
	Item();
	Item(string nameIn, double priceIn, int quantityIn);
	void setName(string nameIn);
	void setPrice(double priceIn);
	void setQuantity(int quantityIn);
	string getName();
	double getPrice();
	int getQuantity();
};

#endif