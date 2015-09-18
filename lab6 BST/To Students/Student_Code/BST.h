#pragma once
#include "BSTInterface.h"
#include "Node.h"
//#include "NodeInterface.h"
class BST :
	public BSTInterface
{
private:
	

public:
	Node* root;
	BST();
	~BST();
	NodeInterface * getRootNode();
	bool add(int data);
	bool recAdd(Node* &cur, int data);
	bool remove(int data);
	bool recRemove(Node* &cur, int data);
	void replac_parent(Node*& temp_root, Node*& cur);
	void clear();
	bool inorderTraversal(NodeInterface* local_root);
};

