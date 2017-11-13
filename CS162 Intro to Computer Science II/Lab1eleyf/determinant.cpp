/**********************************************
**
**	Author: Frederick Eley
**	Date:	10/1/16
**	Description:
**			CS162 400 F2016 
**			Lab1
**			This is the determinant function
**			definition.
**
**********************************************/


#include "determinant.hpp"


/*********************************************
**
**				determinant:
**
**	Function that takes a pointer to a 2D array
**  and an integer which is the size of the
**	matrix as parameters. It will return an 
**	integer value which is the determinant of 
**	the matrix. It will only calculate the 
**	determinant of a 2x2 or 3x3 matrix.
**
**********************************************/


int determinant(int **matrix, int sizeOfMatrix)
	{
		int determ;

		//2x2 matrix
		if (sizeOfMatrix == 2)
		{
			determ = (matrix[0][0] * matrix[1][1])
					-(matrix[0][1] * matrix[1][0]);
		}

		//3x3 matrix
		if (sizeOfMatrix == 3)
		{
			determ = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1]))
					-matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))
					+matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));
		}

		return determ;
	}