/**********************************************
**
**	Author: Frederick Eley
**	Date:	2/1/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 5.b
**			These are the function definitions
**			for the BankAccount class.
**
**********************************************/

#include <string>
#include "BankAccount.hpp"

using namespace std;

/////BankAccount class function definitions


/*********************************************
**
**	Constructor that takes two strings and a
**	double (name, ID, balance) and uses them
**	to initialize the data members.
**
**********************************************/

BankAccount::BankAccount(string name, string ID, double balance)
{
	customerName = name;
	customerId = ID;
	customerBalance = balance;
}


// Get customer name
string BankAccount::getCustomerName()
{
	return customerName;
}


// Getcustomer ID
string BankAccount::getCustomerId()
{
	return customerId;
}


// Get customer balance
double BankAccount::getCustomerBalance()
{
	return customerBalance;
}


// Deduct withdraw amount from balance
void BankAccount::withdraw(double withdrawAmount)
{
	customerBalance -= withdrawAmount;
}


// Add deposit amount to balance
void BankAccount::deposit(double depositAmount)
{
	customerBalance += depositAmount;
}
	
