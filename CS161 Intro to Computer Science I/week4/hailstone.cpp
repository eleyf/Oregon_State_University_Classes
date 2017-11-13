/******************************************************************
**
**	Author:	Frederick Eley
**	Date:	1/26/16
**	Description:
**			CS161 400 W2016 Assignment 4.c
**			This program only contain the definition of the
**			hailstone function.
**
******************************************************************/



/**************************************************************
**
**	This is a function that takes an integer as a parameter
**	and performs the hailstone sequence. It returns how
**	many steps it takes to reach 1. 
**
*************************************************************/

int hailstone(int value)

	{
		int counter = 0;

		while(value != 1)		// If not equal to 1 perform calculation
		{
			// Calculate next value if even
			if(value %2 == 0)
			{
				value /=2;
			}
			
			// Calculate next value if odd
			else
			{
				value *=3;
				value++;
			}

			// Increase counter 
			counter++;
		}


		return counter;
	}