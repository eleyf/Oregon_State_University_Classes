/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 5.a
**			These are the function definitions
**			for the Box class.
**
**********************************************/


#include "Box.hpp"

/////Box class function definitions


/*********************************************
**
**	Default conctructor uses the set methods
**	to initialize each field to 1.
**
*********************************************/

Box::Box()
{
	setHeight(1);
	setWidth(1);
	setLength(1);
}


/*********************************************
**
**	Constructor that takes three doubles and
**	passes them to the set methods to initialize
**	the fields of the Box
**
**********************************************/

Box::Box(double heightIn, double widthIn, double lengthIn)
{
	setHeight(heightIn);
	setWidth(widthIn);
	setLength(lengthIn);
}


// Set height

void Box::setHeight(double heightIn)
{
	height = heightIn;
}


// Set width

void Box::setWidth(double widthIn)
{
	width = widthIn;
}


// Set length

void Box::setLength(double lengthIn)
{
	length = lengthIn;
}

	
// Return volume

double Box::getVolume()
{
	return height * width * length;
}


// Return surface area

double Box::getSurfaceArea()
{
	return (2 * (height * width)) + (2 * (height * length)) + (2 * (width * length));
}
