/***************************
**
**	main to test library
**
****************************/
#include <iostream>
#include "Library.hpp"

int main()
{


Book b1("123", "War and Peace", "Tolstoy");
Book b2("234", "Moby Dick", "Melville");
Book b3("345", "Phantom Tollbooth", "Juster");

Patron p1("abc", "Felicity");
Patron p2("bcd", "Waldo");

Library lib;
lib.addBook(&b1);
lib.addBook(&b2);
lib.addBook(&b3);
lib.addPatron(&p1);
lib.addPatron(&p2);

// test checkOutBook
	std::cout << std::endl << " ";
	std::cout << lib.checkOutBook("bcd", "234") << std::endl;

	std::cout << std::endl << " ";
	std::cout << lib.checkOutBook("bcd", "345") << std::endl;

	std::cout << std::endl << " ";
	std::cout << lib.checkOutBook("bcd", "789") << std::endl;

	std::cout << std::endl << " ";
	std::cout << lib.checkOutBook("bbc", "234") << std::endl << std::endl;

	std::cout << lib.checkOutBook("abc", "234") << std::endl << std::endl;

// p1.addBook(&b1);
// p1.addBook(&b2);
// p1.addBook(&b3);


// test request book
	 // std::cout << std::endl << " ";
	 // std::cout << lib.requestBook("bcd", "345") << std::endl;

	std::cout << std::endl << " ";
	std::cout << lib.requestBook("abc", "789") << std::endl;

	std::cout << std::endl << " ";
	std::cout << lib.requestBook("bbc", "345") << std::endl;

	std::cout << std::endl << " ";
	std::cout << lib.requestBook("abc", "345") << std::endl;

// tests if checked out vector is empty
	if (p2.getCheckedOutBooks().empty())
	{
		std::cout << " checked out vector is empty" << std::endl;
	}


 // tests whats inside checked outvector
	for (int i = 0; i < p2.getCheckedOutBooks().size(); i++)
	{
		std::cout << p2.getCheckedOutBooks()[i]->getTitle() << std::endl;
	}


// move 24 days ahead
for (int i=0; i<24; i++)
 lib.incrementCurrentDate();

// tests incrementCurrentDate

double p1Fine = p1.getFineAmount();
double p2Fine = p2.getFineAmount();


std::cout << " patron 1s fine " << p1Fine << std::endl << std::endl;
std::cout << " patron 2s fine " << p2Fine << std::endl << std::endl;


// tests payFine

std::cout << lib.payFine("bcd", .1) << std::endl << std::endl;

p1Fine = p1.getFineAmount();
p2Fine = p2.getFineAmount();

std::cout << " patron 1s fine " << p1Fine << std::endl << std::endl;
std::cout << " patron 2s fine " << p2Fine << std::endl << std::endl;


// tests return book
std::cout << lib.returnBook("789") << std::endl << std::endl;

std::cout << lib.returnBook("123") << std::endl << std::endl;

std::cout << lib.returnBook("345") << std::endl << std::endl;




// tests whats inside checked outvector
	for (int i = 0; i < p2.getCheckedOutBooks().size(); i++)
	{
		std::cout << p2.getCheckedOutBooks()[i]->getTitle() << std::endl;
	}
/*

lib.checkOutBook("bcd", "234");
for (int i=0; i<7; i++)
 lib.incrementCurrentDate();
lib.checkOutBook("bcd", "123");
lib.checkOutBook("abc", "345");
for (int i=0; i<24; i++)
 lib.incrementCurrentDate();
lib.payFine("bcd", 0.4);
double p1Fine = p1.getFineAmount();
double p2Fine = p2.getFineAmount();

*/



	return 0;
}

/*
// print Book info
std::cout << b1.getIdCode() << " ";
std::cout << b1.getTitle() << " ";
std::cout << b1.getAuthor() << std::endl << std::endl;

std::cout << b2.getIdCode() << " ";
std::cout << b2.getTitle() << " ";
std::cout << b2.getAuthor() << std::endl << std::endl;

std::cout << b3.getIdCode() << " ";
std::cout << b3.getTitle() << " ";
std::cout << b3.getAuthor() << std::endl << std::endl;
*/

// ********************************************************************************


/*
// test enum
// b1.setLocation(ON_SHELF);
if (b1.getLocation() == ON_SHELF)
{
	std::cout << "book on shelf" << std::endl;
}

if (b2.getLocation() == ON_SHELF)
{
	std::cout << "book on shelf" << std::endl;
}

*/


// **************************************************************************************


/*
//print Patron info
std::cout << p1.getIdNum() << " ";
std::cout << p1.getName() << std::endl << std::endl;

std::cout << p2.getIdNum() << " ";
std::cout << p2.getName() << std::endl << std::endl;

*/

// *************************************************************************************

/*
//  tests get patron

	if (lib.getPatron("abc"))
	{	
		std::cout << lib.getPatron("abc")->getName()<< std::endl << std::endl;
	}
	else
	{
		std::cout << " person is not in library" << std::endl << std::endl;
	}

	if (lib.getPatron("bbb"))
	{	
		std::cout << lib.getPatron("bbb")->getName()<< std::endl << std::endl;
	}
	else
	{
		std::cout << " person is not in library" << std::endl << std::endl;
	}

//  tests get book

	if (lib.getBook("234"))
	{	
		std::cout << lib.getBook("234")->getTitle()<< std::endl << std::endl;
	}
	else
	{
		std::cout << " book is not in library" << std::endl << std::endl;
	}

	if (lib.getBook("789"))
	{	
		std::cout << lib.getBook("789")->getTitle()<< std::endl << std::endl;
	}
	else
	{
		std::cout << " book is not in library" << std::endl << std::endl;
	}

*/

// *****************************************************************************************
