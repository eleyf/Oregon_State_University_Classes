/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  10/16/16
** Description:  This is the main program for Assignment1. It
**				 simulates Langston's Ant.
** Input:	Row and column sizes of Grid. Total number of steps.
**			Option to input starting point or have it created
**			randomly.
** Output:	Matrix pattern of Langston's Ant.
*********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "feUtils.hpp"


int main()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	int	x , y;

	std::cout << "Enter low integer: ";

	x = getInt();

	std::cout << "Enter hi integer: ";

	y = getInt();


	std::cout << "In main the interger is " << x << std::endl;


	std::cout << "random 1 : " << getRandom(x, y) << std::endl;
	std::cout << "random 2 : " << getRandom(x, y) << std::endl;
	std::cout << "random 3 : " << getRandom(x, y) << std::endl;
	std::cout << "random 4 : " << getRandom(x, y) << std::endl;
	std::cout << "random 5 : " << getRandom(x, y) << std::endl;
	return 0;
}