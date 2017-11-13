/*********************************************************************  
** Program Filename:  Queue.cpp
** Author:  Frederick Eley  
** Date:  11/18/16
** Description:  These are the function definitions of the Queue
**				 class.
**
**
*********************************************************************/

#include "Queue.hpp"


/* constructor */
Queue::Queue()
{
	front = NULL;
	back = NULL;
}


/* destructor */

Queue::~Queue()
{
	while(front != back)
	{
		QueueNode *temp;
		temp = front;
		front = front->next;
		delete temp;
	}
	// delete back memory not deleted by loop

	delete front;
}

/*********************************************************************  
** Function:  addBack()
** Description: Function that takes an interger as a parameter and
**				adds it to the back of a queue.
**  
*********************************************************************/
void Queue::addBack(int n)
{
	if (front == NULL)  // create first element in queue
	{
		QueueNode *temp;
		temp = new QueueNode;
		temp->num = n;
		temp->next = temp;
		temp->prev = temp;
		front = temp;
		back = temp;
	}

	else if ((back->next)->num != -1) // queue is full
	{
		QueueNode *temp;
		temp = new QueueNode;
		temp->num = n;
		temp->next = front;
		temp->prev = back;
		front->prev = temp;
		back->next = temp;
		back = temp;
	}

	else // queue has empty element after back
	{
		(back->next)->num = n;
		back = back->next;
	}

	std::cout << "Added to queue." << std::endl << std::endl;
}

/*********************************************************************  
** Function:  getFront()
** Description: Function that returns the value of the front element
**				of the queue. It returns a value of -1 if the queue
**				is empty.
**  
*********************************************************************/

int Queue::getFront()
{
	int numRemoved;
	
	if (front == NULL || front->num == -1)
	{
		std::cout << std::endl << "The queue is empty." << std::endl;
		return -1;
	}
	else
	{
		return front->num;
	}
}


/*********************************************************************  
** Function:  removeFront()
** Description: Function that removes a value from the front of a
**				queue and returns its value. A sentinel value of -1
**				is used to indicate that the node is empty.
**  
*********************************************************************/

int Queue::removeFront()
{
	int numRemoved;
	
	if (front == NULL || front->num == -1)
	{
		std::cout << std::endl << "The queue is empty, there is nothing to remove." << std::endl;
		return -1;
	}
	else
	{
		numRemoved = front->num;
		front->num = -1;
		front = front->next;
		return numRemoved;
	}
}

/*********************************************************************  
** Function:  displayQueue()
** Description: Function that displays the contents of the queue.
**  
*********************************************************************/

void Queue::displayQueue() const
{
	if (front == NULL || front->num == -1)
	{
		std::cout << std::endl << "The queue is empty." << std::endl;
	}

	else
	{
		QueueNode *temp;
		temp = front;
		std::cout << std::endl;
		while(temp != back)
		{
			std::cout << temp->num << " ";
			temp = temp->next;
		}

		// print back value not printed by while loop
		std::cout << temp->num << " ";
		std::cout << std::endl;
	}
}


