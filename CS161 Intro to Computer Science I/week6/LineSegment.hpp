/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/9/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 6
**			This is the header file for
**			the LineSegment class.
**
**********************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

// LineSegment class declaration

#include "Point.hpp"

class LineSegment
{
private:
	Point end1;
	Point end2;	  ;

public:
	LineSegment(Point end1In, Point end2In);
	void setEnd1(Point end1In);
	void setEnd2(Point end2In);
	Point getEnd1();
	Point getEnd2();
	double length();
	double slope();
};

#endif