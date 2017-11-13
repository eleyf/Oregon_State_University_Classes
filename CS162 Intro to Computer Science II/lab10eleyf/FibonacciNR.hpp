/*********************************************************************  
** Program Filename:  FibonacciNR.hpp
** Author:  Frederick Eley  
** Date:  12/4/16
** Description:  FibonacciNR Class Header. 
*********************************************************************/

#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

class FibonacciNR 
{
	public:
		FibonacciNR(const unsigned long &n);
		virtual ~FibonacciNR();
		void PrintFibonacci();
	private:
		FibonacciNR();
		unsigned long Fibonacci(const unsigned long &n);
		const unsigned long* n_;
};

#endif