#pragma once
#include "LinkedList.h"
class ORDeque 
{
private:
	LinkedList<int> ORdeque_list;
public:
	ORDeque();
	~ORDeque();
	void push_left(int data);
	void push_right(int data);
	int pop_left();
	int top_left();
	int size();
	bool find(int data);
};

