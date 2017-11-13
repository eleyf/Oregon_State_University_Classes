/*********************************************************
**
**	Author:	Frederick Eley
**	ONID:	eleyf
**	Date:	1/24/16
**	Description:
**			CS 161 400 W2016
**			Assignment 4b
**			This program only contains the definition of
**			a function that sorts the values of three
**			numbers into ascending order.
**			
**********************************************************/


/***************************************************
**
**	This function sorts the values of three numbers
**	into ascending order. The function is of type
**	void and passes the parameters by reference.
**
****************************************************/

void smallSort(int &a, int &b, int &c)
	{
		int temp;

		if (a > b)
		{
			temp = a;
			a = b;
			b = temp;
		}

		if (a > c)
		{
			temp = a;
			a = c;
			c = temp;
		}

		if (b > c)
		{
			temp = b;
			b = c;
			c = temp;
		}

	}