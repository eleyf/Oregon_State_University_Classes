/**********************************************
**
**	Author: Frederick Eley
**	Date:	3/8/16
**	Description:
**			CS161 400 W2016 Assignment 
**			Assignment 10
**			These are the function definitions
**			for the Book class.
**
**********************************************/

#include "Book.hpp"

/*********************************************
**
**	Constructor that takes three parameters
**	idCode, title, and author and initializes
**	them. checkedOutBy and requestedBy are
**	pointers to the Patron class and are
**	initialized to NULL. The location of the
**	book is set to the enum ON_SHELF using the
**	set method.
**
**********************************************/
Book::Book(std::string idc, std::string t, std::string a)
{
	idCode = idc;
	title = t;
	author = a;
	setCheckedOutBy(NULL);
	setRequestedBy(NULL);
	setLocation(ON_SHELF);
}


// get CHECK_OUT_LENGTH
int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}


// get idCode
std::string Book::getIdCode()
{
	return idCode;
}


// get title
std::string Book::getTitle()
{
	return title;
}


// get author
std::string Book::getAuthor()
{
	return author;
}


// get location
Locale Book::getLocation()
{
	return location;
}


// set location
void Book::setLocation(Locale locationIn)
{
	location = locationIn;
}


// get checkedOutBy
Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}


// set checkedOutBy
void Book::setCheckedOutBy(Patron* checkedOutByIn)
{
	checkedOutBy = checkedOutByIn;
}


// get requestedBy
Patron* Book::getRequestedBy()
{
	return requestedBy;
}


// set requestedBy
void Book::setRequestedBy(Patron* requestedByIn)
{
	requestedBy = requestedByIn;
}


// get dateCheckedOut
int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}


// set dateCheckedOut
void Book::setDateCheckedOut(int dateCheckedOutIn)
{
	dateCheckedOut = dateCheckedOutIn;
}
