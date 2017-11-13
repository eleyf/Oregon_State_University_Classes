/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/8/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 10
**			These are the function definitions
**			for the Library class.
**
**********************************************/

#include "Library.hpp"

/*********************************************
**
**	Default constructor that initializes
**	the currentDate to zero.
**
**********************************************/
Library::Library()
{
	currentDate = 0;
}


/*********************************************
**
**				addBook
**
**	Method that takes a pointer to a book in
**	the Book class as a parameter and adds it
**	to the holdings vector using the 
**	push_back method.
**
**********************************************/
void Library::addBook(Book* b)
{
	holdings.push_back(b);
}


/*********************************************
**
**				addPatron
**
**	Method that takes a pointer to a person in
**	the Patron class as a parameter and adds it
**	to the members vector using the 
**	push_back method.
**
**********************************************/
void Library::addPatron(Patron* p)
{
	members.push_back(p);
}


/*********************************************
**
**				checkOutBook
**
**	Method that takes strings of a Patrons
**	idNum and a Books idCode as parameters
**	and 
**	
**	if the specified Book is not in the Library
**	return "book not found"
**
**	if the specified Patron is not in the Library
**	return "patron not found"
**
**	if the specified Book is already checked out
**	return "book already checked out"
**
**	if the specified Book is on hold by another
**	Patron return "book on hold by other patron"
**
**	otherwise update the Book's checkedOutBy,
**	dateCheckedOut and Location.
**	if the Book was on hold for this Patron
**	update requestedBy, update the Patron's,
**	checkedOutBooks and return "check out
**	successful"
**
**********************************************/
std::string Library::checkOutBook(std::string pID, std::string bID)
{
	std::string stateOfBook = "";

	// if the specified Book is in the Library continue
	// else return "book not found"
	if (getBook(bID))
	{	
		// if the specified Patron is in the Library continue
		// else return "patron not found"
		if (getPatron(pID))
		{	
			// if the specified Book is not checked out continue
			// else return "book already checked out"
			if (getBook(bID)->getLocation() != CHECKED_OUT)
			{
				
				// at this point book is either on hold or on shelf

				// if the specified Book is on hold by another
				// patron return "book on hold by other patron"
				if (getBook(bID)->getLocation() == ON_HOLD_SHELF
					&& getBook(bID)->getRequestedBy() != getPatron(pID))
				{
					stateOfBook = "book on hold by other patron";
				}
				
				
				// at this point the book is either on hold for this
				// patron or on shelf
				else
				{

					// update checkedOutBy by dereferencing with
					// getBook and getPatron
					getBook(bID)->setCheckedOutBy(getPatron(pID));

					// update dateCheckedOut by dereferencing with
					// getBook
					getBook(bID)->setDateCheckedOut(currentDate);

					// update requestedBy by dereferencing with getBook
					getBook(bID)->setRequestedBy(NULL);
										
					// update setLocation by dereferencing with
					// getBook
					getBook(bID)->setLocation(CHECKED_OUT);

					// update the patron's checkedOutBooks by
					// dereferencing with getPatron
					getPatron(pID)->addBook(getBook(bID));

					// update state of book
					stateOfBook = "check out successful";
				}

			
			}
			// else for if book is checked out
			else
			{
				stateOfBook = "book already checked out";
			}


		}
		// else for if person is not part of members vector
		else
		{
			stateOfBook = "patron not found";
		}
	}
	// else for if book is not part of holdings vector
	else
	{
		stateOfBook = "book not found";
	}

	return stateOfBook;
}

/*********************************************
**
**				returnBook
**
**	Method that takes a string of a Books
**	idCode as a parameter and 
**
**	if the specified Book is not in the Library,
**	return "book not found"
**
**	if the Book is not checked out,
**	return "book already in library"
**
**	if book is checked out
**	update the Patron's checkedOutBooks;
**	update the Book's location depending on
**	whether another Patron has requested it;
**	update the Book's checkedOutBy;
**	and return "return successful"
**
**********************************************/
std::string Library::returnBook(std::string bID)
{
	std::string stateOfReturnBook = "";

	// if the specified Book is in the
	// Library continue
	// else return "book not found"
	if (getBook(bID))
	{
		// if the specified Book is checked out
		// continue
		// else return "book already in library"
		if(getBook(bID)->getLocation() == CHECKED_OUT)
		{
			
			// dereferenced like crazy to remove the Book from the
			// Patrons checked out vector
			// (getBook(bID)->getCheckedOutBy()) finds the patron with
			// this book which is user to point to removeBook
			// removeBook(getBook(bID)) gets the pointer of the Book
			// with getBook(bID)
			(getBook(bID)->getCheckedOutBy())->removeBook(getBook(bID));
			

			//if the Book is currently requested
			// move it to ON_HOLD_SHELF
			// else move it to ON_SHELF
			if(getBook(bID)->getRequestedBy())
			{
				getBook(bID)->setLocation(ON_HOLD_SHELF);
			} 
			// else move it to ON_SHELF 
			else
			{
				getBook(bID)->setLocation(ON_SHELF);
			}
			
			// set Book checked out by to NULL
			getBook(bID)->setCheckedOutBy(NULL);
			// return successful
			stateOfReturnBook = "return successful";
		}
		// else for if book is not checked out
		else
		{
			stateOfReturnBook = "book already in library";
		}
	
	}
	// else for if book is not part of holdings vector
	else
	{
		stateOfReturnBook = "book not found";
	}

	return stateOfReturnBook;
}

/*********************************************
**
**				requestBook
**
**	Method that takes strings of a Patrons
**	idNum and a Books idCode as parameters
**	and 
**
**	if the specified Book is not in the Library,
**	return "book not found"
**
**	if the specified Patron is not in the
**	Library, return "patron not found"
**
**	if the specified Book is already requested,
**	return "book already on hold"
**
**	update the Book's requestedBy; if the Book
**	is on the shelf, update its location to on
**	hold and return "request successful"
**
**********************************************/
std::string Library::requestBook(std::string pID, std::string bID)
{
	std::string stateOfRequest = "";

	// if the specified Book is in the Library continue
	// else return "book not found"
	if (getBook(bID))
	{
		// if the specified Patron is in the Library continue
		// else return "patron not found"
		if (getPatron(pID))
		{
			// if the specified Book is already requested 
			// return "book already on hold"
			// else continue
			if (getBook(bID)->getLocation() == ON_HOLD_SHELF)
			{
				stateOfRequest = "book already on hold";
			}
			// else make a request for this patron
			else
			{
				// update the Book's requestedBy by dereferencing
				getBook(bID)->setRequestedBy(getPatron(pID));
				// if the Book is on the shelf, update its
				// location to on hold
				if (getBook(bID)->getLocation() == ON_SHELF)
				{
					getBook(bID)->setLocation(ON_HOLD_SHELF);
				}
				// return request successful
				stateOfRequest = "request successful";
			}
		}
		// else for if person is not part of members vector
		else
		{
			stateOfRequest = "patron not found";
		}
	}
	// else for if book is not part of holdings vector
	else
	{
		stateOfRequest = "book not found";
	}

	return stateOfRequest;

}

/*********************************************
**
**				payFine
**
**	Method that takes a patrons idNum and 
**	the amount that is being paid as 
**	parameters, updates the patrons fine,
**	and returns "payment successful"
**
**	If the specified Patron is not in the
**	Library, it returns "patron not found".
**
**********************************************/
std::string Library::payFine(std::string pID, double payment)
{
	std::string stateOfPayFine = "";

	// if the specified Patron is in the Library continue
	// else return "patron not found"
	if (getPatron(pID))
	{
		// amend the fine amount by dereferencing the
		// patron and negating the payment amount
		getPatron(pID)->amendFine(-payment);
		stateOfPayFine = "payment successful";
	}
	// else for if person is not part of members vector
	else
	{
		stateOfPayFine = "patron not found";
	}

	return stateOfPayFine;
}

/*********************************************
**
**				incrementCurrentDate
**
**	Method that increment current date;
**	increases each Patron's fines by 10 cents
**	for each overdue Book they have checked
**	out using the amendFine method.
**
**********************************************/
void Library::incrementCurrentDate()
{
	// increment current date
	currentDate ++;

	// loop for each member in the library
	for (int i = 0; i < members.size(); i++)
	{
		//loop for each book checked out
		// by this particular member
		for (int j = 0; j < members[i]->getCheckedOutBooks().size(); j++)
		{
			// test if book has been checked out more than
			// 21 days using dereferencing twice
			// first to get to the Patron class then to get
			// to the Book class to get the date checked out
			// currentDate - dateCheckedOut
			if ( currentDate
				 - members[i]->getCheckedOutBooks()[j]->getDateCheckedOut()
				 > 21)
			{
				// add 10 cents to fineAmount for this book
				// using dereferencing to get to the Paton class
				// to use amendFine
				members[i]->amendFine(.1);
			}
		}
			 
	
	}



}


/*********************************************
**
**				getPatron
**
**	Method that takes a string of a persons
**	idNum which is in the Patron class as a
**	parameter and returns a pointer to the
**	Patron corresponding to the ID parameter,
**	or NULL if no such Patron is a member.
**
**********************************************/
Patron* Library::getPatron(std::string pID)
{
	bool isMember = false;
	Patron* memberAddress = NULL;

	for (int i = 0; i < members.size(); i++)
	{
		if (members[i]->getIdNum() == pID )
		{
			isMember = true;
			memberAddress = members[i];
		}
	}
	
	return memberAddress;
}

/*********************************************
**
**				getBook
**
**	Method that takes a string of a books
**	idCode which is in the Book class as a
**	parameter and returns a pointer to the
**	Book corresponding to the Book ID parameter,
**	or NULL if no such Book is in the holdings.
**
**********************************************/
Book* Library::getBook(std::string bID)
{
	bool isBookInHoldings = false;
	Book* bookAddress = NULL;

	for (int i = 0; i < holdings.size(); i++)
	{
		if (holdings[i]->getIdCode() == bID )
		{
			isBookInHoldings = true;
			bookAddress = holdings[i];
		}
	}
	
	return bookAddress;
}





























