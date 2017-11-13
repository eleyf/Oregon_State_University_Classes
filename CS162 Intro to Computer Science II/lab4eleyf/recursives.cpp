/*********************************************************************  
** Program Filename:  Recursives.cpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description:  These are the function definitions for the Lab4
**				 recursive functions.
**
*********************************************************************/

#include "recursives.hpp"

/*********************************************************************  
** Function:  revStr()
** Description: Function that takes a string value as a parameter and
**				prints it in reverse order.
**  
*********************************************************************/


void revStr(const std::string &word)
{
	if (word.length() == 1)
	{
		std::cout << word << "\n";
	}
	else
	{
		std::cout << word[word.length() - 1];
		//delete last letter from string
		std::string newWord = word;
		newWord.erase(newWord.length() - 1);
		revStr(newWord);
	}
}


/*********************************************************************  
** Function:  sumArray()
** Description: Function that takes an array of integers as a
**				parameter and returns the sum of its elements.
**  
*********************************************************************/


int sumArray(const int arr[], int size)
{
	if (size <= 0)
	{
		return 0;
	}
	else
	{
		return arr[size - 1] + sumArray(arr, size -1);
	}
}


/*********************************************************************  
** Function:  tri()
** Description: Function that takes an integer as a parameter and
**				returns its triangular.
**  
*********************************************************************/


int tri(int num)
{
	if (num <= 0)
	{
		return 0;
	}
	else
	{
		return num + tri(num - 1);
	}
}
