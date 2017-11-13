/**********************************************************************************************
Name: Ken Hayward
Date: 2-17-16
Description: CPP File for a function that returns the mode of an array as a vector object. Assignment #7
************************************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

vector<int> findMode(int array1[], int size) {
	//above line takes the arguments of the array and it's size as an int. 

	//creates the vector to return. 
	vector<int> theMode;

	//create a "parallel" (not in the textbook sense, but...) vector. This stores the number of instances of each occurance for number in the provided array... 
	// For Example, If you provide an array of :
	//1,2,4,68,1,3,1,
	//You'd have: 
	//Array1: 1,1,1,2,3,68
	//countVector: 3,3,3,1,1,1
	vector<int> CountVector;

	//set the number of elements in countVector to the number in the array, initialize each to zero.
	for (int i = 0; i < size; i++) {
		CountVector.push_back(0);
	};

	//temp for the fequency of each item, and a temp for whatever the highest  number of repeats is. 
	int frequency = 0;
	int highestFreq = 0;


	//Prepare the array by sorting it smallest to largest:  
	sort(array1, array1 + size);
	

	//compare the values from the left (compare element 1 vs element 2, element 3, etc.;
	//then sets a count in the count vector at the appropriate spot. 

	for (int i = 0; i < size; i++) {

		for (int j = 0; j < size; j++) {
			if (i != j && array1[i] == array1[j]) {
				frequency++;
			}
			//sets the frequency of the current place in the array as "The highest frequency".
			if (frequency > highestFreq) {
				highestFreq = frequency;
			}
		}

		//this sets a frequency for each position. If the frequency is bigger zero or the previous position, it sets max freq. to that.
		CountVector[i] = frequency;

		frequency = 0;

	};
	//append the number with the highest frequency to the returned vector. 
	//if there is multiple numbers with the highest frequency, it returns both, assuming they are different.
	//Since our array is sorted above, I made it so that if  while the loop checks 
	//and sees if the current value is equal to the previous element 
	for (int i = 0; i < size; i++) {

		if (CountVector[i] == highestFreq && array1[i] != array1[i-1]) {
			theMode.push_back(array1[i]);
			}

		}
		

return theMode;
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