#include "IRDeque.h"


IRDeque::IRDeque()
{
}


IRDeque::~IRDeque()
{
}
void IRDeque::push_left(int data)
{
	IRdeque_list.insertHead(data);
}

int IRDeque::pop_left()
{
	int var = IRdeque_list.at(0);
	IRdeque_list.remove(IRdeque_list.at(0));
	return var;
}
int IRDeque::pop_right()
{
	int var = IRdeque_list.at(IRdeque_list.find_end());
	IRdeque_list.remove(IRdeque_list.at(IRdeque_list.find_end()));
	return var;
}
int IRDeque::top_left()
{
	return IRdeque_list.at(0);
}
int IRDeque::top_right()
{
	return IRdeque_list.at(IRdeque_list.find_end());
}
int IRDeque::size()
{
	return IRdeque_list.size();
}

bool IRDeque::find(int data)
{
	return IRdeque_list.find(data);
}