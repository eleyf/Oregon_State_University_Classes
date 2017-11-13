/*********************************************************************  
** Program Filename:  searchAndSort.cpp
** Author:  Frederick Eley  
** Date:  11/13/16
** Description:  These are the function definitions for the Lab7
**				 search and sort functions.
**
*********************************************************************/

#include "searchAndSort.hpp"

/*********************************************************************  
** Function:  linSearch()
** Description: Function that takes an array of integers, the size of
**				the array, and the integer to be searched for as
**				parameters and returns the array position of the
**				integer if found. If the interger is not in the array
**				a value of -1 is returned as an indicator. The
**				function makes use of the linear search algorithm.
**				The algorithm used is based on the example given in
**				the CS162 Intro to Progamming II Searching slide
**				page 6.
**  
*********************************************************************/


int linSearch(const int a[], int size, int val)
{
	for(int i = 0; i < size; i++)
	{
		if(a[i] == val) 
			{
				return i;
			}
	}
	return -1;
}

/*********************************************************************  
** Function:  insertSort()
** Description: Function that takes an array of integers, the size of
**				the array, and the integer to be searched for as
**				parameters and returns the array position of the
**				integer if found. If the interger is not in the array
**				a value of -1 is returned as an indicator. The
**				function makes use of the linear search algorithm. The
**				algorithm used is based on the example given in C++
++				Early Objects 8th Edition - Gaddis pg 611.
**  
*********************************************************************/


void insertSort(int array[], int size) 
{
	int start, 
		minPosition,
		minValue;

		for(start = 0; start < (size - 1); start++)
		{
			minPosition = start;
			minValue = array[start];
			for(int i = start + 1; i < size; i++)
			{
				if (array[i] < minValue)
				{
					minValue = array[i];
					minPosition = i;
				}
			}
			array[minPosition] = array[start];
			array[start] = minValue;
		}
}

/*********************************************************************  
** Function:  biSearch()
** Description: Function that takes an array of integers, the size of
**				the array, and the integer to be searched for as
**				parameters and returns the array position of the
**				integer if found. If the interger is not in the array
**				a value of -1 is returned as an indicator. The
**				function makes use of the linear search algorithm.
**				The algorithm used is based on the example given in
**				the CS162 Intro to Progamming II Searching slide
**				page 11.
**  
*********************************************************************/

int biSearch(int array[], int size, int val)
{
	int low = 0;
	int high = size - 1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		int diff = array[mid] - val;
		if(diff == 0) // array[mid] == val
		{
			return mid;
		}
		else if (diff < 0) // array[mid] < val
		{
			low = mid + 1;
		}
		else // array[mid] > val
		{
			high = mid - 1;
		} 
	}
	return -1;
}


























