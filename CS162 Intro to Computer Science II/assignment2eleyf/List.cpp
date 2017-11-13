/*********************************************************************  
** Program Filename:  List.cpp
** Author:  Frederick Eley  
** Date:  10/23/16
** Description:  These are the function definitions of the List
**				 class.
** Input:	The default constructor creates a dynamic array of 4 Items.
**
**			The deconstructor deallocates the memory of the dynamic
**			array.
**
*********************************************************************/

#include "List.hpp"

/* static member definitions */
double List::totalPrice = 0.0;
int List::numberOfItems = 0;


/* constructors */
List::List()
{
	arraySize = 4;

	itemArray = new Item[arraySize];
}

/* deconstructor */
List::~List()
	{
		if (itemArray)
		{
			delete [] itemArray;
		}
	}


/*********************************************************************  
** Function:  addToList();
** Description: Function that adds an item to the list and updates
				the running total of items in the list.
**
**  
*********************************************************************/
void List::addToList()
{
	std::string name,
				unit;
	int 		quantity,
				counter = 0;
	double		price;
	bool		itemExists = false;
	Item 		tempItem;

	/*check size of array and increase it if it's full*/
	if (numberOfItems == arraySize)
	{
		arraySize *= 2;
		/* create temp array and copy values to it */ 
		Item 	*tempArray = new Item[arraySize];

		for (int i = 0; i < numberOfItems; i++)
		{
			tempArray[i] = itemArray[i];
		}

		delete [] itemArray;

		/* transfer temp pointer address to array*/
		itemArray = tempArray;

		tempArray = NULL;
	}

	/* Prompt user and get info of item to be added and store it in a temp item */
	std::cout << "What is the name of the item you want to add? ";
	std::cin  >> name;
	tempItem.setItemName(name);

	std::cout << "What is the unit size of the item? ";
	std::cin  >> unit;
	tempItem.setUnit(unit);

	std::cout << "What is the number of the items you want to add? ";
	std::cin  >> quantity;
	tempItem.setQuantity(quantity);

	std::cout << "What is the price per unit of the item? ";
	std::cin  >> price;
	tempItem.setUnitPrice(price);

	std::cout << std::endl;


	/* while loop tests if item already exists */
	while ( !itemExists && counter < numberOfItems)
	{
		if (tempItem == itemArray[counter])
		{
			itemExists = true;
		}
		else
		{
			counter++;
		}
	}

	/* if item exists update quantity and total price */
	if (itemExists)
	{
		itemArray[counter].setQuantity(quantity + itemArray[counter].getQuantity());
		totalPrice += tempItem.extendedPrice();
	}

	/* if item doesn't exist add it to the end of the list
		and update total price and number of items */
	else
	{

		itemArray[numberOfItems].setItemName(name);

		itemArray[numberOfItems].setUnit(unit);

		itemArray[numberOfItems].setQuantity(quantity);

		itemArray[numberOfItems].setUnitPrice(price);

		totalPrice += itemArray[numberOfItems].extendedPrice();
		numberOfItems++;
	}
}

/*********************************************************************  
** Function:  removeFromList();
** Description: Function that removes the last item from the list.
**
**  
*********************************************************************/
void List::removeFromList()
{
	/* test if the list is already empty */
	if (numberOfItems > 0 )
	{	
		numberOfItems--;

		totalPrice -= itemArray[numberOfItems].extendedPrice();

		itemArray[numberOfItems].setItemName(" ");

		itemArray[numberOfItems].setUnit(" ");

		itemArray[numberOfItems].setQuantity(0);

		itemArray[numberOfItems].setUnitPrice(0.0);

		std::cout << "The last item on the list has been removed." << std::endl;
	}
	else
	{
		std::cout << std::endl;
		std::cout << "The list is alreay empty. There are no items to remove.";
		std::cout << std::endl;
	}
}


/*********************************************************************  
** Function:  printList();
** Description: Function that displays each item in the list and the
**				the total price for all the items.
**
**  
*********************************************************************/
void List::printList()
{
	for (int i = 0; i < numberOfItems; i++)
	{
		itemArray[i].printItem();
	}

	std::cout << std::endl;
	std::cout << "There are " << numberOfItems << " items in the list, with ";
	std::cout << "a total cost of $" << std::fixed << std::setprecision(2) << totalPrice << std::endl; 
	std::cout << std::endl;
}
