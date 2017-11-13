/*********************************************************************  
** Program Filename:  Buffer.cpp
** Author:  Frederick Eley  
** Date:  11/27/16
** Description:  These are the function definitions of the Buffer
**				 class.
**
**
*********************************************************************/

#include "Buffer.hpp"


/* constructor */
Buffer::Buffer()
{

}


/* destructor */
Buffer::~Buffer()
{

}

/*********************************************************************  
** Function:  genNum();
** Description: Function that generates a random interger in the
**				range of 0 - 1000.
**  
*********************************************************************/
int Buffer::genNum()
{
	return getRandom(1000);
}

/*********************************************************************  
** Function: bufferPush()
** Description: Function that takes an interger value of a percentage
**				as a parameter and pushes a random integer value to
**				the queue at that percentage rate.
**  
*********************************************************************/
void Buffer::bufferPush(int i)
{
	if (getRandom(1, 100) <= i)
	{
		intQueue.push(genNum());
	}
}

/*********************************************************************  
** Function: bufferPop()
** Description: Function that takes an interger value of a percentage
**				as a parameter and removes an integer from the
**				queue at that percentage rate.
**  
*********************************************************************/
void Buffer::bufferPop(int i)
{
	if (getRandom(1, 100) <= i)
	{
		intQueue.pop();
	}
}

/*********************************************************************  
** Function: bufferEmpty()
** Description: Function that tests to see if the buffer queue is empty.
**  
*********************************************************************/
bool Buffer::bufferEmpty()
{
	return intQueue.empty();
}

/*********************************************************************  
** Function: bufferClear()
** Description: Function that clears all values from the buffer queue.
**  
*********************************************************************/
void Buffer::bufferClear()
{
	while ( !intQueue.empty())
  	{
     intQueue.pop();
  	}
}

/*********************************************************************  
** Function: bufferSize()
** Description: Function that returns the size of the buffer queue.
**  
*********************************************************************/
int Buffer::bufferSize()
{
	return intQueue.size();
}
