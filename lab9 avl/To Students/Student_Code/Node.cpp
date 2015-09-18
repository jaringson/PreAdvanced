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


int Node::inorderTraversal(NodeInterface* local_root,  int counter)
{
	//cout << "here 2" << endl;
	counter++;
	//cout << "      " << counter << endl;
	if (height < counter)
	{
		height = counter;
	}
	if (local_root == NULL)
	{
		return 0;
	}
	else
	{
		inorderTraversal(local_root->getLeftChild(), counter);
		//for (int i = 0; i < counter; i++) { cout << " "; }
		//cout << local_root->getData() << endl;
		inorderTraversal(local_root->getRightChild(), counter);
		return height;
	}
}

int Node::getHeight()
{
	height = 0;
	//cout << "here 1" << endl;
	int height_left = inorderTraversal(left_child, 0);
	//cout << data << endl;
	int height_right = inorderTraversal(right_child, 0);
	if (height_left > height_right)
	{
		return height_left;
	}
	else
	{
		return height_right;
	}
}





