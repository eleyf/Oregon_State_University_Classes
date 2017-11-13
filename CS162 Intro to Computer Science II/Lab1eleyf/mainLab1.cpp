/**********************************************
**
**	Author: Frederick Eley
**	Date:	10/1/16
**	Description:
**			CS162 400 F2016 
**			Lab1
**			This is the main program for lab 1.
**			It uses the readMatrix function
**			to fill a matrix, and the determinant
**			function to calculate the determinant.
**			It then displays the matrix and the
**			determinant to the user.
**
**********************************************/


#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

int main()
{
	int matrixSize;
	int **p2DArray;

	std::cout << std::endl;
	std::cout << "Enter the size of matrix (2 or 3):" << std::endl;
	std::cin  >> matrixSize;
	
	//input validation
	while ((matrixSize != 2) && (matrixSize != 3))
		{
			std::cout << std::endl;
			std::cout << "The size of the matrix must be 2 or 3.";
			std::cout << std::endl;
			std::cout << "Enter the size of matrix (2 or 3):" << std::endl;
			std::cin  >> matrixSize;
		}
	std::cout << std::endl;

	//create matrix
	p2DArray = new int*[matrixSize];
	for (int i = 0; i < matrixSize; i++)
		{
			p2DArray[i] = new int[matrixSize];
		}
	
	
	//fill matrix
	readMatrix( p2DArray, matrixSize);

	std::cout << std::endl;
	std::cout << "The determinant of the matrix:" << std::endl << std::endl;

	//print matrix
	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			std::cout << ' ' << p2DArray[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << "is: ";
	std::cout << determinant( p2DArray, matrixSize) << std::endl;
	std::cout << std::endl;


		
	//De-Allocate Array
	for (int i = 0; i < matrixSize; i++)
		{
			delete [] p2DArray[i];
		}
	delete[] p2DArray;
				



	return 0;
}