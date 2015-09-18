#include "Node.h"


Node::Node(int data_var, Node* left, Node* right)
{
	data = data_var;
	left_child = left;
	right_child = right;
}


Node::~Node()
{
}

int Node::getData()
{
	return data;
}

NodeInterface * Node::getLeftChild()
{
	return left_child;
}

NodeInterface * Node::getRightChild()
{
	return right_child;
}



