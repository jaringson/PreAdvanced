#pragma once
#include "NodeInterface.h"
#include <iostream>
class Node :
	public NodeInterface
{
public:
	int height;
	int data;
	//int counter;
	//bool increase;
	enum balance_type {LEFT_HEAVY = -1, BALANCED = 0, RIGHT_HEAVY = +1};
	balance_type balance;
	Node* left_child;
	Node* right_child;
	Node(int data_var, Node* left, Node* right);
	~Node();
	int getData();
	NodeInterface * getLeftChild();
	NodeInterface * getRightChild();
	int getHeight();
	int inorderTraversal(NodeInterface* local_root,  int counter);
};

