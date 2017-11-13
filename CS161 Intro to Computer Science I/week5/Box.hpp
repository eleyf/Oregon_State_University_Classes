/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 5.a
**			This is the header file for
**			the Box class.
**
**********************************************/


#ifndef BOX_HPP
#define BOX_HPP

////Box class declaration

class Box
{
private:
	double	height;
	double	width;
	double	length;

public:
	Box();
	Box(double heightIn, double widthIn, double lengthIn);
	void setHeight(double heightIn);
	void setWidth(double widthIn);
	void setLength(double lengthIn);
	double getVolume();
	double getSurfaceArea();
};

#endif
