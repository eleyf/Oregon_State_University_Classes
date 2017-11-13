/**************************************************************************************************
** Program Filename:  FibonacciNR.cpp
** Author:  Frederick Eley  
** Date:  12/4/16
** Description:  These are the function definitions of the FibonacciNR
**				 class.
**
**				The methods make use of code from:
**				https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
**
***************************************************************************************************/
 
#include "FibonacciNR.hpp"
#include <iostream>

FibonacciNR::FibonacciNR()
{

}

FibonacciNR::FibonacciNR(const unsigned long &n):n_(&n)
{

}

FibonacciNR::~FibonacciNR()
{

}

unsigned long FibonacciNR::Fibonacci(const unsigned long &n)
{
	unsigned long first =0;
	unsigned long second=1;
	unsigned long counter=2;
	while (counter < n)
	{
		unsigned long temp = second;
		second = first + second;
		first = temp;
		++counter;
	}
	
	if(n==0)
		return 0;
	else
		return first + second;
}
	
void FibonacciNR::PrintFibonacci()
{
	const unsigned long result = Fibonacci(*n_);
	std::cout << *n_ << "th fibonacci Number:" << result << std::endl;
}