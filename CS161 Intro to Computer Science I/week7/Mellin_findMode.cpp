/****************************************************************
 * Author: Matt Mellin
 * Date: 2/16/2016
 * Description: Function that takes an array and its size as a parameter
 * and determines the mode of the array, returning it as a vector 
 * organized in ascending order.
 * **************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findMode(int arr[], int length);  //Prototype for findMode function
/* 
int main()
{	
	const int SIZE = 4; 
	int input[SIZE] = {3, 6, 0, 1};

	vector<int> modeVector = findMode(input, SIZE);

	for(int i = 0; i < modeVector.size(); i++)
	{
		cout << modeVector[i] << endl;
	}
	
	return 0;
}
*/

/***********************************************
 * findMode function
 * Takes in integer array and size, returns
 * vector of modes.
 * *******************************************/

vector<int> findMode(int arr[], int length)
{
	vector<int> modeVector;  //define vector that will contain final results
	vector<int> tempVector;  //define temporary vector to find modes
	int modeValue = 0;	 //modeValue will be equivalent to the 
				 //frequency of the mode(s).

/***********************************
 * Determine the frequency of the mode(s)
 * so this value can be used to identify
 * the mode(s) when the array is iterated
 * through a second time
 * ********************************/	
	for(int i = 0; i < length; i++)
	{
		int count = 0;
		for(int j = 0; j < length; j++)
		{
			if(arr[i] == arr[j])
			{
				count++;
			}
		}
		if(count > modeValue)
		{
			modeValue = count;
		}
	}
/*************************************************************
 * Increase count every time a value increases.
 * If the final count for each array element is equivalent to 
 * modeValue, save that element by pushing it to tempVector.
 * ************************************************************/
	for(int i = 0; i < length; i++)
	{
		int count = 0;
		for(int j = 0; j < length; j++)
		{
			if(arr[i] == arr[j])
			{
				count++;
			}
		}
		if(count == modeValue)
		{
		
			tempVector.push_back(arr[i]);
		}
	}
	//Sort tempVector so values are in asceinding order.
	sort(tempVector.begin(), tempVector.end());
	//Set modeVector's initial value to the initial value in the 
	//sorted tempVector.
	modeVector.push_back(tempVector[0]);

/*******************************************************************************
 * Iterate through tempVector comparing every value (starting at the second value
 * hence i = 1) with the previous value. Whenever the element of tempVector
 * being iterated is NOT equal to the value before it, that element will be
 * added to the result vector called modeVector. The vector has been sorted 
 * into ascending order therefore if the element being iterated is equivalent 
 * to the i - 1 element that element is a repeat and is not allowed into 
 * the results vector named modeVector.
 * **************************************************************************/
	for(int i = 1; i < tempVector.size() ; i++)
	{
		if(tempVector[i] != tempVector[i-1])
		{
			modeVector.push_back(tempVector[i]);
		}
	}	
	return modeVector;
}



int main()
{   
    const int SIZE = 5; 
    int input[SIZE] = {3, 1, 6, 1, 6};

    vector<int> modeVector = findMode(input, SIZE);

    for(int i = 0; i < modeVector.size(); i++)
    {
        cout << modeVector[i] << endl;
    }
    
    return 0;
}
