#pragma once
#include "LinkedList.h"
class Deque 
{
private:
	LinkedList<int> deque_list;
public:
	Deque();
	~Deque();
	void push_left(int data);
	void push_right(int data);
	int pop_left();
	int pop_right();
	int top_left();
	int top_right();
	int size();
	bool find(int data);
};

