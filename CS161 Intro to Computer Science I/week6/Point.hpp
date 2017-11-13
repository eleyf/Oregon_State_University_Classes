/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/8/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 6
**			This is the header file for
**			the Point class.
**
**********************************************/

#ifndef POINT_HPP
#define POINT_HPP


// Point class declaration

class Point
{
private:
	double xCoord,
		   yCoord;

public:
	Point();
	Point(double xCoordIn, double yCoordIn);
	void setXCoord(double xCoordIn);
	void setYCoord(double yCoordIn);
	double getXCoord() const;
	double getYCoord() const;
	double distanceTo(const Point & secondPoint);
};

#endif