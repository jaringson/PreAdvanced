#pragma once
#include "LinkedList.h"
class IRDeque 
{
private:
	LinkedList<int> IRdeque_list;
public:
	IRDeque();
	~IRDeque();
	void push_left(int data);
	int pop_left();
	int pop_right();
	int top_left();
	int top_right();
	int size();
	bool find(int data);
};

