/*
Jaron Ellingson
CS 235 Winter 2015 Midterm
*/
#include <iostream>
#include <string>
#include "CircularDLLInterface.h"

class CircularDLL :
	public CircularDLLInterface
{
private:
	struct Node
	{

		Node(string data_var, Node* next_var, Node* prev_var)
		{
			data = data_var;
			nextValue = next_var;
			prevValue = prev_var;
		}
		string data;
		Node* nextValue;
		Node* prevValue;
	};
	Node* head;
	Node* tail;
public:
	CircularDLL();
	~CircularDLL();
	bool insertHead(string name);
	bool insertTail(string name);
	bool insertAt(string name, int index);
	bool removeHead();
	bool removeTail();
	bool removeAt(int index);
	void clear();
	int size();
	string atFromHead(int index);
	string atFromTail(int index);
};

