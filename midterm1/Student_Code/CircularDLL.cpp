/*
Jaron Ellingson
CS 235 Winter 2015 Midterm
*/
#include "CircularDLL.h"


CircularDLL::CircularDLL()
{
	head = NULL;
	tail = NULL;
}


CircularDLL::~CircularDLL()
{
	clear();
}

bool CircularDLL::insertHead(string name)
{
	bool proceed = true;
	//Node* traverse = head;
	if (head == NULL)
	{
		Node* new_head = new Node(name, head, tail);
		head = new_head;
		tail = new_head;
		return true;
	}
	for (int i = 0; i < CircularDLL::size(); i++)
	{
		if (CircularDLL::atFromHead(i) == name)
		{
			proceed = false;
		}
	}
	if (proceed)
	{
		Node* new_head = new Node(name, head, tail);
		head->prevValue = new_head;
		tail->nextValue = new_head;
		head = new_head;
		return true;
	}
	return false;
}

bool CircularDLL::insertTail(string name)
{
	//Node* traverse = head;
	bool proceed = true;

	if (head == NULL)
	{
		Node* new_head = new Node(name, head, tail);
		head = new_head;
		tail = new_head;
		return true;
	}
	//traverse = head;
	for (int i = 0; i < CircularDLL::size(); i++)
	{
		if (CircularDLL::atFromHead(i) == name)
		{
			proceed = false;
		}
	}
	if (proceed)
	{
		Node* new_tail = new Node(name, head, tail);
		tail->nextValue = new_tail;
		head->prevValue = new_tail;
		tail = new_tail;
		return true;
	}
	return false;
}
bool CircularDLL::insertAt(string name, int index)
{
	Node* traverse = head;
	bool proceed = true;
	int counter = 0;
	if (index > CircularDLL::size() || index <= -1) //Checks if index is too large or too small
	{
		return false;
	}
	while (traverse != tail)
	{
		if (traverse->data == name || traverse->nextValue->data == name)
		{
			proceed = false;
		}
		traverse = traverse->nextValue;
	}
	if (index == CircularDLL::size())
	{
		return CircularDLL::insertTail(name);
	}
	if (index == 0)
	{
		return CircularDLL::insertHead(name);
	}
	traverse = head;
	while (proceed == true && traverse != tail)
	{
		if (counter == index)
		{
			Node* previous = traverse->prevValue;
			Node* insertion = new Node(name, traverse, previous);
			traverse->prevValue = insertion;
			previous->nextValue = insertion;
			return true;
		}
		traverse = traverse->nextValue;
		counter++;
	}
	return false;
}
bool CircularDLL::removeHead()
{
	if (CircularDLL::size() == 0)
	{
		return false;
	}
	else if (tail == head)
	{
		delete head;
		head = NULL;
		tail == NULL;
	}
	else
	{
		head->nextValue->prevValue = head->prevValue;
		head->prevValue->nextValue = head->nextValue;
		Node* temp_holder = head;
		head = head->nextValue;
		delete temp_holder;
		return true;
	}
}
bool CircularDLL::removeTail()
{
	if (CircularDLL::size() == 0)
	{
		return false;
	}
	else if (tail == head)
	{
		delete head;
		head = NULL;
		tail == NULL;
	}
	else
	{
		tail->nextValue->prevValue = tail->prevValue;
		tail->prevValue->nextValue = tail->nextValue;
		Node* temp_holder = tail;
		tail = tail->prevValue;
		delete temp_holder;
		return true;
	}

}
bool CircularDLL::removeAt(int index)
{
	if (index > CircularDLL::size() || index <= -1) //Checks if index is too large or too small
	{
		return false;
	}
	if (index == 0) //Checks Head
	{
		return CircularDLL::removeHead();
	}
	if (index == CircularDLL::size() - 1) //Checks Tail
	{
		return CircularDLL::removeTail();
	}
	Node* traverse = head;
	int counter = 0;
	while (traverse != tail)
	{
		if (counter == index)
		{
			Node* previous = traverse->prevValue;
			Node* temp_holder = traverse;
			traverse = traverse->nextValue;
			delete temp_holder;
			traverse->prevValue = previous;
			previous->nextValue = traverse;	
			return true;
		}
		traverse = traverse->nextValue;
		counter++;
	}
	return false;
}
void CircularDLL::clear()
{
	int size_holder = CircularDLL::size();
	for (int i = 0; i < size_holder; i++)
	{
		CircularDLL::removeAt(0);
	}
}
int CircularDLL::size()
{
	int counter = 0;
	Node* traverse = head;
	if (head == NULL)
	{
		return 0;
	}
	if (head == tail)
	{
		return 1;
	}
	while (traverse != tail)
	{
		counter++;
		traverse = traverse->nextValue;
	}
	return counter + 1; //Add the one to count the tail
}


string CircularDLL::atFromHead(int index)
{
	if (index > CircularDLL::size() || index <= -1) //Checks if index is too large or too small
	{
		return "invalid";
	}
	if (index == 0) //Checks Head
	{
		return head->data;
	}
	if (index == CircularDLL::size() - 1) //Checks Tail
	{
		return tail->data;
	}
	Node* traverse = head;
	int counter = 0;
	while (traverse != tail)
	{
		if (counter == index)
		{
			return traverse->data;
		}
		traverse = traverse->nextValue;
		counter++;
	}
	return "invalid";
}
string CircularDLL::atFromTail(int index)
{
	if (index > CircularDLL::size() || index <= -1) //Checks if index is too large or too small
	{
		return "invalid";
	}
	if (index == 0) //Checks Head
	{
		return tail->data;
	}
	if (index == CircularDLL::size() - 1) //Checks Tail
	{
		return head->data;
	}
	Node* traverse = tail;
	int counter = 0;
	while (traverse != tail)
	{
		if (counter == index)
		{
			return traverse->data;
		}
		traverse = traverse->prevValue;
		counter++;
	}
	return "invalid";
}
