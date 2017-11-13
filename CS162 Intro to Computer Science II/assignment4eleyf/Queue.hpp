/*********************************************************************  
** Program Filename:  Queue.hpp
** Author:  Frederick Eley  
** Date:  11/6/16
** Description:  Queue Class Header. 
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include "Creature.hpp"


class Queue
{
protected:
	struct 	QueueNode
	{
		Creature 	*fighter;
		QueueNode 	*next;
	};

	QueueNode *front, *rear;
	

public:
	Queue();
	~Queue();
    void 		push(Creature *f);
    Creature *	pop();
    void 		displayQueue() const;
};

#endif