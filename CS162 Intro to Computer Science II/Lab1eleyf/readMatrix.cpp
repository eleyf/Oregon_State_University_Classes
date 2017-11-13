/**********************************************
**
**	Author: Frederick Eley
**	Date:	10/1/16
**	Description:
**			CS162 400 F2016 
**			Lab1
**			This is the readMatrix function
**			definition.
**
**********************************************/



#include "readMatrix.hpp"
#include <iostream>

/*********************************************
**
**				readMatrix:
**
**	Function that takes a pointer to a 2D array
**  and an integer which is the size of the
**	matrix as parameters. It prompts the user 
**	to fill a square matrix.
**
**********************************************/


void readMatrix(int **matrix, int sizeOfMatrix)
{
	int counter = 1;

	for (int i = 0; i < sizeOfMatrix; i++)
	{
		for (int j = 0; j < sizeOfMatrix; j++)
		{
			std::cout << "Enter matrix value number " << counter;
			std::cout << " of " << sizeOfMatrix * sizeOfMatrix << ".";
			std::cout << std::endl;
			std::cin  >> matrix[i][j];
			counter++;
			std::cout << std::endl;
		}
	}
}