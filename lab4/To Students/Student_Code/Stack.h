#pragma once
#include "LinkedList.h"
class Stack 
{
private:
	LinkedList<int> stack_list;

public:
	Stack();
	~Stack();
	void push(int data);
	int pop();
	int top();
	int size();
	bool find(int data);
};

