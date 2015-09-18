#include "Queue.h"


Queue::Queue()
{
}


Queue::~Queue()
{
}
void Queue::push(int data)
{
	queue_list.insertTail(data);
}

int Queue::pop()
{
	int var = queue_list.at(0);
	queue_list.remove(queue_list.at(0));
	return var;
}

int Queue::front()
{
	if (queue_list.size() <= 0)
	{
		return -1;
	}
	else
	{
		return queue_list.at(0);
	}
}

int Queue::size()
{
	return queue_list.size();
}

bool Queue::find(int data)
{
	return queue_list.find(data);
}
