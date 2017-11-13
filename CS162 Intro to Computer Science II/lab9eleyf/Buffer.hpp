/*********************************************************************  
** Program Filename:  Buffer.hpp
** Author:  Frederick Eley  
** Date:  11/27/16
** Description:  Buffer Class Header. 
*********************************************************************/

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <iostream>
#include <string>
#include <queue>
#include "feUtils.hpp"


class Buffer
{
private:
	std::queue<int> intQueue;

public:
	Buffer();
	~Buffer();
	int genNum();
	void bufferPush(int i);
	void bufferPop(int i);
	bool bufferEmpty();
	void bufferClear();
	int bufferSize();
};

#endif