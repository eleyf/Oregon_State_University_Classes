/*********************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  11/13/16
** Description: This is the main program for Lab7. It 
**
*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "feUtils.hpp"
#include "searchAndSort.hpp"


int main()
{
	const int MAXARRAYSIZE = 10;
	int switchChoice,
		searchTarget,
		position;
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string inputFileName,
				outputFileName;


	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   SORT AND SEARCH FUNCTIONS" << std::endl << std::endl;
		std::cout << "1. Linear Search Function" << std::endl;
		std::cout << "2. Insert Sort Function" << std::endl;
		std::cout << "3. Binary Search Function (CAN ONLY BE USED ON A SORTED LIST)" << std::endl;
		std::cout << "4. Exit Program" << std::endl;
		std::cout << std::endl << "Enter the choice of the function that you want to utilize (1 - 3)";
		std::cout << std::endl << "or enter (4) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(4);

		//enter switch if not (4) else exit program
		if (switchChoice != 4)
		{
			switch(switchChoice)
			{
				// Linear Search Function
				case 1:	// Prompt user for the name of the file to be opened
						std::cout << std::endl << "What is the name of the file you want to search? ";
						std::cin  >> inputFileName;

						// Open the input file
						inputFile.open(inputFileName.c_str());

						// If file opens 
						if (inputFile)
						{
							// create array to hold input values
							int inputArray[MAXARRAYSIZE];
							int arrayCounter = 0;

							// Loop reading in values until the end of the file
							while (inputFile >> inputArray[arrayCounter])
							{
								arrayCounter++;
							}

							// Close the input file
							inputFile.close();

							// prompt for target value
							std::cout << std::endl << "What is the integer you want to search for? ";
							searchTarget = getInt();
							position = linSearch(inputArray, arrayCounter, searchTarget);

							// display results of search
							if (position == -1)
							{
								std::cout << std::endl << "The integer is not in the list." << std::endl;
								std::cout << std::endl;
							}
							else
							{
								std::cout << std::endl << "The integer is in position number ";
								std::cout << position << "." << std::endl;
								std::cout << std::endl;
							}
						}

						// If file does not open
						else
						{
							std::cout << std::endl << "Could not access file." << std::endl << std::endl;
						}
						
						break;

				// Insert Sort Function
				case 2: // Prompt user for the name of the file to be opened
						std::cout << std::endl << "What is the name of the file you want to sort? ";
						std::cin  >> inputFileName;

						// Open the input file
						inputFile.open(inputFileName.c_str());

						// If file opens 
						if (inputFile)
						{
							// create array to hold input values
							int inputArray[MAXARRAYSIZE];
							int arrayCounter = 0;

							// Loop reading in values until the end of the file
							while (inputFile >> inputArray[arrayCounter])
							{
								arrayCounter++;
							}

							// Close the input file
							inputFile.close();

							// Sort array
							insertSort(inputArray, arrayCounter);

							// prompt user for output file name
							std::cout << std::endl << "What is the name of the file you want the sorted list written to? ";
							std::cin  >> outputFileName;

							// Open output file
							outputFile.open(outputFileName.c_str());

							// Write values to the output file
							for (int i = 0; i < arrayCounter; i++)
							{
								outputFile << inputArray[i] << " ";
							}

							// Close output file
							outputFile.close();

							std::cout << std::endl << "The array has been sorted and written to the file.";
							std::cout << std::endl;

						}

						// If file does not open
						else
						{
							std::cout << std::endl << "Could not access file." << std::endl << std::endl;
						}

						break;

				// Binary Search Function
				case 3:	// Prompt user for the name of the file to be opened
						std::cout << std::endl << "What is the name of the file you want to search? ";
						std::cin  >> inputFileName;

						// Open the input file
						inputFile.open(inputFileName.c_str());

						// If file opens 
						if (inputFile)
						{
							// create array to hold input values
							int inputArray[MAXARRAYSIZE];
							int arrayCounter = 0;

							// Loop reading in values until the end of the file
							while (inputFile >> inputArray[arrayCounter])
							{
								arrayCounter++;
							}

							// Close the input file
							inputFile.close();

							// prompt for target value
							std::cout << std::endl << "What is the integer you want to search for? ";
							searchTarget = getInt();
							position = biSearch(inputArray, arrayCounter, searchTarget);

							// display results of search
							if (position == -1)
							{
								std::cout << std::endl << "The integer is not in the list." << std::endl;
								std::cout << std::endl;
							}
							else
							{
								std::cout << std::endl << "The integer is in position number ";
								std::cout << position << "." << std::endl;
								std::cout << std::endl;
							}
						}

						// If file does not open
						else
						{
							std::cout << std::endl << "Could not access file." << std::endl << std::endl;
						}
						
						break;
			}
		}
	}
	// Loop again if user did not choose 4 to exit
	while (switchChoice != 4);

	std::cout << std::endl << "The program is ending." << std::endl;
	std::cout << std::endl;

	return 0;
}