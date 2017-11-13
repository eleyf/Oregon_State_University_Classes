/*********************************************************************  
** Program Filename:  Queue.cpp
** Author:  Frederick Eley  
** Date:  11/6/16
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
	rear = NULL;
}


/* destructor */
Queue::~Queue()
{
	while(front != NULL)
	{
		QueueNode *temp;
		temp = front;
		front = front->next;
		delete temp;
	}
}

/*********************************************************************  
** Function:  push()
** Description: Function that takes an interger as a parameter and
**				adds it to the back of a queue.
**  
*********************************************************************/
void Queue::push(int n)
{
	QueueNode *temp;
	temp = new QueueNode;
	temp->num = n;
	temp->next = NULL;
	if(rear == NULL)
	{
		front = temp;
		rear = temp;
	}
	else
	{
		rear->next = temp;
		rear = temp;
	}
}

/*********************************************************************  
** Function:  pop()
** Description: Function that removes an interger from the front of a
**				queue and returns its value.
**  
*********************************************************************/
int Queue::pop()
{
	int numRemoved;
	
	if (front == NULL)
	{
		std::cout << "The queue is empty, there is nothing to remove." << std::endl;
		return 0;
	}
	else
	{
		QueueNode *temp;
		temp = front;
		numRemoved = front->num;
		front = front->next;
		delete temp;
		if(front == NULL)
		{
			rear = NULL;
		}
		return numRemoved;
	}
}


/*********************************************************************  
** Function:  displayQueue()
** Description: Function that displays the contents of the queue.
**
**  
*********************************************************************/
void Queue::displayQueue() const
{
	QueueNode *temp;
	temp = front;
	while(temp != NULL)
	{
		std::cout << temp->num << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


