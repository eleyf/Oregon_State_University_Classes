#include <iostream>
#include "Point.hpp"
#include "LineSegment.hpp"

using namespace std;

int main()
{
	Point p1(4.3, 7.52);
	Point p2(4.3, 1.5);


	cout << endl;
	cout << "point 1 x is " << p1.getXCoord() << endl;
	cout << "point 1 y is " << p1.getYCoord() << endl;
	cout << "point 2 x is " << p2.getXCoord() << endl;
	cout << "point 2 y is " << p2.getYCoord() << endl;

	double dist = p1.distanceTo(p2);

	cout << endl << "distance is " << dist << endl << endl;

	LineSegment ls1(p1, p2);
	
//	double length = ls1.length();
//	double slope = ls1.slope();
	
	cout << "segment tests " << endl;
	
	double length = ls1.length();

	cout << "length is " << length << endl << endl;

	double slope = ls1.slope();

	cout << "slope is " << slope << endl << endl;
//	cout << "point 2 y is " << ls1.getEnd2() << endl;
//	cout << "point 2 x is " << p2.getXCoord() << endl;
//	cout << "point 2 y is " << p2.getYCoord() << endl;



	return 0;
}


