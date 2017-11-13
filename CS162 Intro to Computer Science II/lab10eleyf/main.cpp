/***************************************************************************************  
** Program Filename:  main.cpp
** Author:  Frederick Eley  
** Date:  12/4/16
** Description: This is the main program for Lab10. It calculates a
**				a Fibonacci number using an iterative method and a
**				recursive method and calculates the respective times
**				to do each.
**
**				The time calculation makes use of code from:
**				https://www.cs.rutgers.edu/~pxk/416/notes/c-tutorials/gettime.html
**
**				The Fibonacci methods make use of code from:
**				https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
**
****************************************************************************************/

#include <iostream>
#include "feUtils.hpp"
#include "FibonacciNR.hpp"
#include "FibonacciR.hpp"
#include <stdio.h>	/* for printf */
#include <stdint.h>	/* for uint64 definition */
#include <time.h>	/* for clock_gettime */

#define BILLION 1000000000L


int main()
{
	uint64_t diff;
	struct timespec start, end;
	int num,
		switchChoice;;

	do 
	{
		// Display menu
		std::cout << std::endl;
		std::cout << "   Fibonacci" << std::endl << std::endl;
		std::cout << "1. Fibonacci Calculator" << std::endl;
		std::cout << "2. Exit Program" << std::endl;
		std::cout << std::endl << "Enter (1) to calculate a Fibonacci number ";
		std::cout << std::endl << "or enter (2) to exit: ";

		// Validate selection
		switchChoice = getSwitchChoice(2);

		//enter switch if not (2) else exit program
		if (switchChoice != 2)
		{
			switch(switchChoice)
			{
				// Fibonacci Calculator
				case 1:	
						std::cout << "Enter the Fibonacci number to be calculated:" << std::endl;
						num = getInt();
						while (num < 0)
						{
							std::cout << "The value must be a positive integer." << std::endl;
							std::cout << "Enter the Fibonacci number to be calculated:" << std::endl;
							num = getInt();
						}


						/* measure interative time */
						clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
						
						FibonacciNR fnr(num);
						std::cout << std::endl;
						fnr.PrintFibonacci();
						
						clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

						diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
						printf("Iterative elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);



						/* measure recursive time */
						clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
						
						FibonacciR fr(num);
						std::cout << std::endl;
						fr.PrintFibonacci();
						
						clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

						diff = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
						printf("Recursive elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

						std::cout << std::endl;

						break;

			}
		}
	}
	// Loop again if user did not choose 2 to exit
	while (switchChoice != 2);

	std::cout << std::endl << "The program is ending." << std::endl;
	std::cout << std::endl;

	return 0;
}