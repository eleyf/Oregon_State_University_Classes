/*****************************
**
**	main to test class Box
**
*****************************/

#include <iostream>
#include "Box.hpp"

using namespace std;

/**********************************************************
////Header for class Box

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
*************************************************************/

//// Main for testing

int main()
{
	Box	test1,
		test2(4,3,4);

	cout << "default values" << endl;
	cout << test1.getVolume() << endl;
	cout << test1.getSurfaceArea() << endl << endl;

	cout << "3 values" << endl;
	cout << test2.getVolume() << endl;
	cout << test2.getSurfaceArea() << endl << endl;



	return 0;
}

/****************************************************************
/////Class definitions


/////Constructors

Box::Box()
{
	setHeight(1);
	setWidth(1);
	setLength(1);
}


Box::Box(double heightIn, double widthIn, double lengthIn)
{
	setHeight(heightIn);
	setWidth(widthIn);
	setLength(lengthIn);
}


void Box::setHeight(double heightIn)
{
	height = heightIn;
}


void Box::setWidth(double widthIn)
{
	width = widthIn;
}


void Box::setLength(double lengthIn)
{
	length = lengthIn;
}

	
double Box::getVolume()
{
	return height * width * length;
}


double Box::getSurfaceArea()
{
	return (2 * (height * width)) + (2 * (height * length)) + (2 * (width * length));
}

***************************************************************************************/











