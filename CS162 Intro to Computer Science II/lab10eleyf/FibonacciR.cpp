/**************************************************************************************************
** Program Filename:  FibonacciR.cpp
** Author:  Frederick Eley  
** Date:  12/4/16
** Description:  These are the function definitions of the FibonacciR
**				 class.
**
**				The methods make use of code from:
**				https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c
**
***************************************************************************************************/

 #include "FibonacciR.hpp"
 #include <iostream>

 FibonacciR::FibonacciR()
 {
 
 } 
 
 FibonacciR::FibonacciR(const int &n):n_(&n)
 {

 }

FibonacciR::~FibonacciR()
{

}

int FibonacciR::Fibonacci(const int &n)
{
	if(n==0)
	{
		return 0;
	}
	else if(n==1)
	{
		return 1;
	}
	return Fibonacci(n-1) + Fibonacci(n-2);
}

void FibonacciR::PrintFibonacci()
{
	int FibonaciNum=Fibonacci(*n_);
	std::cout << *n_<< "th fibonaci number: " << FibonaciNum << std::endl;
}