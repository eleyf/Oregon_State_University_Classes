/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 5.b
**			This is the header file for
**			the BankAccount class.
**
**********************************************/


#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

using namespace std;

////BankAccount class declaration

class BankAccount
{
private:
	string	customerName;
	string	customerId;
	double	customerBalance;

public:
	BankAccount(string name, string ID, double balance);
	string 	getCustomerName();
	string 	getCustomerId();
	double 	getCustomerBalance();
	void 	withdraw(double withdrawAmount);
	void 	deposit(double depositAmount);

};

#endif
