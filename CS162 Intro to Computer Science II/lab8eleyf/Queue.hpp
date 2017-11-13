/*********************************************************************  
** Program Filename:  Queue.hpp
** Author:  Frederick Eley  
** Date:  11/18/16
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
		int			num;
		QueueNode 	*next, *prev;
	};

	QueueNode *front, *back;
	

public:
	Queue();
	~Queue();
    void 	addBack(int n);
    int		getFront();
    int		removeFront();
    void 	displayQueue() const;
};

#endif