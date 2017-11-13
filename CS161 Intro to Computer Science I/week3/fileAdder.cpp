/***************************************************************
**
**	Author: Frederick Eley
**  ONID:	eleyf
**	Date:	1/18/2016
**	Description: Week 3 Assignment 3.b
**
**				This program gets the name of a file to be 
**				read from the user. If the file exists, the 
**				numbers in the file are added together and 
**				written to a file named "sum.txt". If the 
**				file does not exist or cannot be opened an
**				error message is displayed.
**
****************************************************************/


#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string filename;
	int value,
		totalValue = 0;		// Accumulator value initialzed to zero


	// Prompt user for the name of the file to be opened
	cout << "Enter the name of the file:" << endl;
	cin  >> filename;

	// Open the input file
	inputFile.open(filename.c_str());

	// If file opens 
	if (inputFile)
	{
		// Work with input

		// Loop reading in values until the end of the file
		while (inputFile >> value)
		{
			//Accumulate total
			totalValue += value;
		}

		// Close the input file
		inputFile.close();

		
		//Work with output

		// Open output file
		outputFile.open("sum.txt");

		// Write total to the output file
		outputFile << totalValue << endl;

		// Close output file
		outputFile.close();

	}

	// If file does not open
	else
	{
		cout << endl << "could not access file" << endl << endl;
	}


	return 0;
}
