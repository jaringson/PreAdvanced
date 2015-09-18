#pragma once
#include "NodeInterface.h"
class Node :
	public NodeInterface
{
private:
	
public:
	int data;
	Node* left_child;
	Node* right_child;
	Node(int data_var, Node* left, Node* right);
	~Node();
	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
};

