/*****************************
**
**	main to test class BankAccount
**
*****************************/

#include <iostream>
#include <string>

#include "BankAccount.hpp"

using namespace std;

/*
////Header for class BankAccount

class BankAccount
{
private:
	string	customerName;
	string	customerId;
	double	customerBalance;

public:
	BankAccount(string name, string ID, double balance);
	string getCustomerName();
	string getCustomerId();
	double getCustomerBalance();
	void withdraw(double withdrawAmount);
	void deposit(double depositAmount);

};
*/

//////////////////////////////////////////////////////////////////////////////////
//// Main for testing

int main()
{
	BankAccount	test1("fred", "fe1689", 0),
				test2("mark", "me1689", 100);

	cout << endl << "fred values" << endl;
	cout << test1.getCustomerName() << endl;
	cout << test1.getCustomerId() << endl;
	cout << test1.getCustomerBalance() << endl << endl;
	test1.deposit(100);
	cout << test1.getCustomerBalance() << endl << endl;
	test1.withdraw(150);
	cout << test1.getCustomerBalance() << endl << endl;

	cout << endl << "mark values" << endl;
	cout << test2.getCustomerName() << endl;
	cout << test2.getCustomerId() << endl;
	cout << test2.getCustomerBalance() << endl << endl;
	test2.deposit(100);
	cout << test2.getCustomerBalance() << endl << endl;
	test2.withdraw(150);
	cout << test2.getCustomerBalance() << endl << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
/////Class definitions


/////Constructors


/*

BankAccount::BankAccount(string name, string ID, double balance)
{
	customerName = name;
	customerId = ID;
	customerBalance = balance;
}


string BankAccount::getCustomerName()
{
	return customerName;
}


string BankAccount::getCustomerId()
{
	return customerId;
}


double BankAccount::getCustomerBalance()
{
	return customerBalance;
}


void BankAccount::withdraw(double withdrawAmount)
{
	customerBalance -= withdrawAmount;
}


void BankAccount::deposit(double depositAmount)
{
	customerBalance += depositAmount;
}
	

*/







