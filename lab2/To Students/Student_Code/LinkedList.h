#pragma once
#include "LinkedListInterface.h"
#include <stdexcept>

template <class T>
class LinkedList :
	public LinkedListInterface<T>
{
private:
	struct Node
	{
		
		Node(T data_var, Node* next_var /*= NULL*/)
		{
			data = data_var;
			nextValue = next_var;
		}
		T data;
		Node* nextValue;
	};
	Node* head;

public:
	
	LinkedList<T>()
	{
		head = NULL;
	};
	~LinkedList<T>()
	{
		clear();
	};
	void insertHead(T value)
	{
		bool proceed = true;
		Node* traverse = head;
		
		if (head == NULL)
		{
			Node* new_head = new Node(value, head);
			head = new_head;
		}

		while (traverse != NULL && proceed == true)
		{
			if (traverse->data == value)
			{
				proceed = false;
			}
			
			traverse = traverse->nextValue;
			
			if (traverse == NULL && proceed == true)
			{
				Node* new_head = new Node(value, head);
				head = new_head;
			}
		}

		//Great System to Check what is Happening
		/*system("pause");
		traverse = head;
		while (traverse != NULL)
		{
			cout << traverse->data << endl;
			traverse = traverse->nextValue;
		}*/
		
	}
	void insertTail(T value)
	{
		Node* traverse = head;
		bool proceed = true;
		if (head == NULL)
		{
			Node* new_head = new Node(value, head);
			head = new_head;
		}

		while (traverse != NULL && proceed == true)
		{
			Node* previous = traverse;
		
			if (traverse->data == value)
			{
				proceed = false;
			}
			traverse = traverse->nextValue;
			if (traverse == NULL && proceed == true)
			{
				Node* new_tail = new Node(value, NULL);
				previous->nextValue = new_tail;
			}
		}
		//Great System to Check what is Happening
		/*system("pause");
		traverse = head;
		while (traverse != NULL)
		{
		cout << traverse->data << endl;
		traverse = traverse->nextValue;
		}*/
	}
	void insertAfter(T value, T insertionNode)
	{
		//find insertionNode
		Node* traverse = head;
		bool proceed = true;
		while (traverse != NULL)
		{

			if (traverse->data == value)
			{
				proceed = false;
			}
			traverse = traverse->nextValue;
		}
		traverse = head;
		while (proceed == true && traverse != NULL)
		{
			if (traverse->data == insertionNode)
			{
				if (traverse->nextValue == NULL)
				{
					Node* insertion = new Node(value, NULL);
					traverse->nextValue = insertion;
					break;
				}
				Node* previous = traverse;
				traverse = traverse->nextValue;
				Node* insertion = new Node(value, traverse);
				previous->nextValue = insertion;
			}
			traverse = traverse->nextValue;
		}
		
	}
	void remove(T value)
	{
		Node* traverse = head;
		Node* previous = head;
		while (traverse != NULL)
		{
			if (traverse->data == value)
			{
				if (traverse == head)
				{
					traverse = traverse->nextValue;
					delete previous;
					head = traverse;
					break;
				}
				previous->nextValue = traverse->nextValue;
				delete traverse;
				break;
			}
			
			previous = traverse;
			traverse = traverse->nextValue;
		}
	
		
		

	}
	void clear()
	{
	  	Node* traverse = head;
		Node* previous = head;
		while (traverse != NULL)
		{
			previous = traverse;
			traverse = traverse->nextValue;
			remove(previous->data);
		}

		

	}
	T at(int index)
	{
		int counter = 0;
		Node* traverse = head;
		while (traverse != NULL)
		{
			if (counter == index)
			{
				return traverse->data;
			}
			counter++;
			traverse = traverse->nextValue;
		}
		if (counter <= index || index < 0)
		{
			throw  out_of_range("Out of Range");
		}
	}
	int size()
	{
		int counter = 0;
		Node* traverse = head;
		while (traverse != NULL)
		{
			counter++;
			traverse = traverse->nextValue;
		}
		return counter;
	}

};

