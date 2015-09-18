#include "ORDeque.h"


ORDeque::ORDeque()
{
}


ORDeque::~ORDeque()
{
}

void ORDeque::push_left(int data)
{
	ORdeque_list.insertHead(data);
}
void ORDeque::push_right(int data)
{

	ORdeque_list.insertTail(data);
}
int ORDeque::pop_left()
{
	int var = ORdeque_list.at(0);
	ORdeque_list.remove(ORdeque_list.at(0));
	return var;
}
int ORDeque::top_left()
{
	return ORdeque_list.at(0);
}
int ORDeque::size()
{
	return ORdeque_list.size();
}

bool ORDeque::find(int data)
{
	return ORdeque_list.find(data);
}