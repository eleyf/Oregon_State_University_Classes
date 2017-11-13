/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/8/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 10
**			These are the function definitions
**			for the Patron class.
**
**********************************************/

#include "Patron.hpp"

/*********************************************
**
**	Constructor that takes an idNum and name
**	as parameters and initializes them.
**	fineAmount is initialized to zero.
**
**********************************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0.0;
}

// get idNum
std::string Patron::getIdNum()
{
	return idNum;
}

// get name()
std::string Patron::getName()
{
	return name;
}

// get checkedOutBooks
std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}


/*********************************************
**
**				addBook
**
**	Method that takes a pointer to a book in
**	the Book class as a parameter and adds it
**	to the checkedOutBooks vector using the 
**	push_back method.
**
**********************************************/
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}


/*********************************************
**
**				removeBook
**
**	Method that takes a pointer to a book in
**	the Book class as a parameter and removes
**	it from checkedOutBooks vector.
**
**********************************************/

void Patron::removeBook(Book* b)
{
	// loop thru checked out vector
	for (int i = 0; i < checkedOutBooks.size(); i++)
	{
		// if value of this vector space is the same
		// as the Book parameter passed, erase it
		if (checkedOutBooks[i] == b)
		{	
			checkedOutBooks.erase(checkedOutBooks.begin() + i);
		}
	}
}


// get fineAmount
double Patron::getFineAmount()
{
	return fineAmount;
}


/*********************************************
**
**				amendFine
**
**	Method that takes a double as a
**	parameter and increases fineAmount if it's
**	and decreases fineAmount if it's negative.
**
**********************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}




































