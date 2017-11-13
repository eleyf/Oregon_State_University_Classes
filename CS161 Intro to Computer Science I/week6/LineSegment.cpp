/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/9/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 6
**			These are the function definitions
**			for the LineSegment class.
**
**********************************************/

#include "Point.hpp"
#include "LineSegment.hpp"

/*********************************************
**
**	Constructor that takes two Point class 
**	objects and passes them to the set methods
**	to initialize end points.
**
**********************************************/

LineSegment::LineSegment(Point end1In, Point end2In)
{
	setEnd1(end1In);
	setEnd2(end2In);
}	


// Set end1
void LineSegment::setEnd1(Point end1In)
{
	end1 = end1In;
}


// Set end2
void LineSegment::setEnd2(Point end2In)
{
	end2 = end2In;
}


// Return end1
Point LineSegment::getEnd1()
{
	return end1;
}


// Return end2
Point LineSegment::getEnd2()
{
	return end2;
}


/***************************************************
**
**			Length
**	
**	Returns the length of the LineSegment by using
**	the distanceTo method from the Point class on 
**	its endpoints.
**
****************************************************/ 

double LineSegment::length()
{
	return end1.distanceTo(end2);
}


/***************************************************
**
**			Slope
**	
**	Returns the slope of the LineSegment.
**
**		m = (y1 - y2)/(x1 - x2)
**
****************************************************/ 
double LineSegment::slope()
{
	double 	yDifference = end1.getYCoord() - end2.getYCoord(),
			xDifference = end1.getXCoord() - end2.getXCoord();

	return yDifference/ xDifference;
}