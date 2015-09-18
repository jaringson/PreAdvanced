#include "Stack.h"


Stack::Stack()
{
}


Stack::~Stack()
{
}
void Stack::push(int data)
{
	stack_list.insertHead(data);	
}

int Stack::pop()
{
	int var = stack_list.at(0);
	stack_list.remove(stack_list.at(0));	
	return var;
}

int Stack::top()
{
	return stack_list.at(0);
}

int Stack::size()
{
	return stack_list.size();
}

bool Stack::find(int data)
{
	return stack_list.find(data);
}
