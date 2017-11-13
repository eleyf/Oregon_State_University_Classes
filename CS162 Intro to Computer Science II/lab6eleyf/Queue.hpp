/*********************************************************************  
** Program Filename:  Queue.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Queue Class Header. 
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream> 


class Queue
{
protected:
	struct 	QueueNode
	{
		int	num;
		QueueNode 	*next;
	};

	QueueNode *front, *rear;
	

public:
	Queue();
	~Queue();
    void 	push(int n);
    int		pop();
    void 	displayQueue() const;
};

#endif