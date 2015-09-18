#include "Deque.h"


Deque::Deque()
{
}


Deque::~Deque()
{
}
void Deque::push_left(int data)
{
	deque_list.insertHead(data);
}

void Deque::push_right(int data)
{
	deque_list.insertTail(data);
}

int Deque::pop_left()
{
	int var = deque_list.at(0);
	deque_list.remove(deque_list.at(0));
	return var;
}

int Deque::pop_right()
{
	int var = deque_list.at(deque_list.find_end());
	deque_list.remove(deque_list.at(deque_list.find_end()));
	return var;
	
}

int Deque::top_left()
{

	return deque_list.at(0);
}

int Deque::top_right()
{
	return deque_list.at(deque_list.find_end());
}

int Deque::size()
{
	return deque_list.size();
}

bool Deque::find(int data)
{
	return deque_list.find(data);
}
