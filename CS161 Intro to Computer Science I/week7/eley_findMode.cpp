/*********************************************************
**
**	Author:	Frederick Eley
**	ONID:	eleyf
**	Date:	2/15/16
**	Description:
**			CS 161 400 W2016
**			Assignment 7
**			This program contains the definition of
**			the findMode function.
**			
**********************************************************/

#include <vector>
#include <algorithm>
using namespace std;


/**********************************************************
**
**				findMode
**
**	This function takes an array of integers and the
**	the size of the array as parameters and returns
**	the mode or modes of the intergers in the array
**	as a vector in ascending order.
**
***********************************************************/

vector<int> findMode (int intArray[], int arraySize)
{
	int instanceCount,
		vectorCount,
		highestCount = 0;

	vector<int> modeVector;
	bool alreadyInVector = false;


	// Loop to find highest count
	for (int i=0; i < arraySize; i++)
	{
		instanceCount = 0;

		for (int j=0; j < arraySize; j++)
		{
			if (intArray[i] == intArray[j])
			{
				instanceCount++;
			}	

		}

		if (instanceCount > highestCount)
		{
			highestCount = instanceCount;
		}	

	}

	// Loop to find modes
	for (int i=0; i < arraySize; i++)
	{
		instanceCount = 0;

		for (int j=0; j < arraySize; j++)
		{
			if (intArray[i] == intArray[j])
			{
				instanceCount++;
			}	

		}
		
		// add to vector if mode
		if (instanceCount == highestCount)
		{
			// if no values in vector yet
			if (modeVector.empty())
			{
				modeVector.push_back(intArray[i]);
			}
			
			// if values exist in the vector check to see if the
			// mode value is already in the vector
			else
			{
				// test if int is already in the vector
				vectorCount = 0;
				
				while (!alreadyInVector && vectorCount < modeVector.size())
				{
					if (intArray[i] == modeVector[vectorCount])
					{
						alreadyInVector = true;
					}

					vectorCount++;
				}

				// push if not already in vector
				if (!alreadyInVector)
				{
					modeVector.push_back(intArray[i]);
				}

			}
		}	

	}

	
	// sort vector
	sort(modeVector.begin(), modeVector.end());


	// return vector
	return modeVector;

}


#include <iostream>

int main()
{	
	const int SIZE = 4; 
	int input[SIZE] = {3, 6, 6, 3};

	vector<int> modeVector = findMode(input, SIZE);

	for(int i = 0; i < modeVector.size(); i++)
	{
		cout << modeVector[i] << endl;
	}
	
	return 0;
}