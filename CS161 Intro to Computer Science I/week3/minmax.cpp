/*************************************************
**
**	Author: Frederick Eley
**	ONID:	eleyf
**	Date:	1/18/2016
**	Description:  Week 3 Assignment 3.a
**				
**				This program displays the smallest
**				and largest numbers input by the
**				user.
**
**************************************************/

#include <iostream>

using namespace std;


int main ()
{
	int totalNumberOfIntegers,
		value,
		minValue,
		maxValue;


	// prompt user for input
	cout << "How many integers would you like to enter?" << endl;
	cin  >> totalNumberOfIntegers;
	cout << "Please enter " << totalNumberOfIntegers << " integers." << endl;
	
	//	initialize loop to run number of times specified
	for (int x=0; x < totalNumberOfIntegers; x++)
	
	{
		// read value 
		cin >> value;
		cin.ignore();


		// on the first run set values of min and max 
		if (x == 0)
		{
			minValue = value;
			maxValue = value;
		}

		
		// compare the value to min and max and adjust accordingly
		else 
		{
			if (value < minValue)
			{
				minValue = value;
			}

			if (value > maxValue)
			{
				maxValue = value;
			}
		}

	}	

	// print min and max values
	cout << "min: " << minValue << endl;
	cout << "max: " << maxValue << endl << endl;

	return 0;
}


