#pragma once
#include "LinkedList.h"
class Queue 
{
private:
	LinkedList<int> queue_list;

public:
	Queue();
	~Queue();
	void push(int data);
	int pop();
	int front();
	int size();
	bool find(int data);
};

