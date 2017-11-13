/*********************************************************************  
** Program Filename:  FibonacciR.hpp
** Author:  Frederick Eley  
** Date:  12/4/16
** Description:  FibonacciR Class Header. 
*********************************************************************/

 
 #ifndef FIBONACCIR_HPP
 #define FIBONACCIR_HPP

class FibonacciR
{
	public:
		FibonacciR(const int &n);
		virtual ~FibonacciR();
		void PrintFibonacci();
	private:
		FibonacciR();
		int Fibonacci(const int &n);
		const int *n_;
};
#endif