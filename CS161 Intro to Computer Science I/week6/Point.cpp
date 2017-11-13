/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/8/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 6
**			These are the function definitions
**			for the Point class.
**
**********************************************/


#include "Point.hpp"
#include <cmath>

/////Box class function definitions

/*********************************************
**
**	Default conctructor uses the set methods
**	to initialize each field to 0.
**
*********************************************/

Point::Point()
{
	setXCoord(0);
	setYCoord(0);
}

	
/*********************************************
**
**	Constructor that takes two doubles and
**	passes them to the set methods to initialize
**	the x and y coordinates of a point.
**
**********************************************/

Point::Point(double xCoordIn, double yCoordIn)
{
	setXCoord(xCoordIn);
	setYCoord(yCoordIn);
}	


// Set x coordinate
void Point::setXCoord(double xCoordIn)
{
	xCoord = xCoordIn;
}


// Set y coordinate
void Point::setYCoord(double yCoordIn)
{
	yCoord = yCoordIn;
}


// Return x coordinate as a constant
double Point::getXCoord() const
{
	return xCoord;
}


// Return y coordinate as a constant
double Point::getYCoord() const
{
	return yCoord;
}


/*********************************************
**
**				distanceTo:
**
**	Function that takes a constant reference
**  to another Point as a parameter.
**	It returns the distance from the Point
**	that called the method to the Point that
**	was passed as a parameter.
**	
**	distance = sqrt [(x1 - x2)^2 + (y1 - y2)^2]
**
**********************************************/
double Point::distanceTo(const Point & secondPoint)
{
	double	XDistance = getXCoord() - secondPoint.getXCoord(),
			YDistance = getYCoord() - secondPoint.getYCoord();

	return sqrt( pow(XDistance,2) + pow(YDistance,2) );
}