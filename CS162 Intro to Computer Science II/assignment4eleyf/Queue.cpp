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
** Description: Function that takes a pointer to a Creature as a
**				parameter and adds it to the back of a queue.
**  
*********************************************************************/
void Queue::push(Creature *f)
{
	QueueNode *temp;
	temp = new QueueNode;
	temp->fighter = f;
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
** Description: Function that removes an Creature pointer from the front of a
**				queue and returns its value.
**  
*********************************************************************/
Creature * Queue::pop()
{
	Creature * fighterRemoved;
	
	if (front == NULL)
	{
		return 0;
	}
	else
	{
		QueueNode *temp;
		temp = front;
		fighterRemoved = front->fighter;
		front = front->next;
		delete temp;
		if(front == NULL)
		{
			rear = NULL;
		}
		return fighterRemoved;
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
		std::cout << (temp->fighter)->getTypeOfCreature() << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}


