#pragma once
#include "AVLInterface.h"
#include "Node.h"
class AVL :
	public AVLInterface
{
public:
	AVL();
	~AVL();
	bool increase;
	bool decrease;
	int height;
	Node* root;
	NodeInterface* getRootNode();
	bool add(int data);
	bool replace_parent(Node*& temp_root, Node*& cur);
	bool recAdd(Node* &cur, int data);
	bool remove(int data);
	void remove_rebalance_left(Node* &cur);
	void remove_rebalance_right(Node* &cur);
	bool recRemove(Node* & cur, int data);
	int inorderTraversal(Node* local_root, int counter);
	int getHeight();
	bool fourty_seven_test;
};

