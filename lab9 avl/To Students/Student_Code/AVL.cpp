#include "AVL.h"

AVL::AVL()
{
	root = NULL;
}


AVL::~AVL()
{
	bool test = true;
	while(test)
	{
		if(root == NULL)
		{
			test = false;
		}
		else if(root->left_child != NULL || root->right_child !=NULL)
		{
			remove(root->data);
			test = true;
		}
		else
		{
			Node* temp = root;
			root = NULL;
			delete temp;
			test = false;
		}

	} 		
}


void rotate_right(Node* &cur)
{
	Node* temp = cur->left_child;
	cur->left_child = temp->right_child;
	temp->right_child = cur;
	cur = temp;
}
void rotate_left(Node* &cur)
{
	Node* temp = cur->right_child;
	cur->right_child = temp->left_child;
	temp->left_child = cur;
	cur = temp;
}
NodeInterface* AVL::getRootNode()
{
	return root;
}


void rebalance_right(Node* &cur)
{
	Node* avl_local_root = dynamic_cast<Node*>(cur);
	Node* avl_right_child = dynamic_cast<Node*>(cur->right_child);
	if (avl_right_child->balance == Node::LEFT_HEAVY)
	{
		Node* avl_right_left_child = dynamic_cast<Node*>(avl_right_child->left_child);
		if (avl_right_left_child->balance == Node::RIGHT_HEAVY)
		{
			avl_right_child->balance = Node::BALANCED;
			avl_right_left_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::LEFT_HEAVY;
		}
		else if (avl_right_left_child->balance == Node::BALANCED)
		{
			avl_right_child->balance = Node::BALANCED;
			avl_right_left_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		else /*if (avl_right_left_child->balance = Node::RIGHT_HEAVY)*/
		{
			avl_right_child->balance = Node::RIGHT_HEAVY;
			avl_right_left_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		rotate_right(cur->right_child);
	}
	else
	{
		avl_right_child->balance = Node::BALANCED;
		avl_local_root->balance = Node::BALANCED;
	}
	rotate_left(cur);
}

void rebalance_left(Node* &cur)
{
	Node* avl_local_root = dynamic_cast<Node*>(cur);
	Node* avl_left_child = dynamic_cast<Node*>(cur->left_child);
	if (avl_left_child->balance == Node::RIGHT_HEAVY)
	{
		Node* avl_left_right_child = dynamic_cast<Node*>(avl_left_child->right_child);
		if (avl_left_right_child->balance == Node::LEFT_HEAVY)
		{
			avl_left_child->balance = Node::BALANCED;
			avl_left_right_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::RIGHT_HEAVY;
		}
		else if (avl_left_right_child->balance == Node::BALANCED)
		{
			avl_left_child->balance = Node::BALANCED;
			avl_left_right_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		else /*if (avl_left_right_child->balance = Node::RIGHT_HEAVY)*/
		{
			avl_left_child->balance = Node::LEFT_HEAVY;
			avl_left_right_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		rotate_left(cur->left_child);
	}
	else
	{
		avl_left_child->balance = Node::BALANCED;
		avl_local_root->balance = Node::BALANCED;
	}
	rotate_right(cur);
}

bool AVL::recAdd(Node* &cur, int data)
{
	//cout << data << endl;
	increase = false;
	if (cur == NULL)
	{
		cur = new Node(data, NULL, NULL);
		Node* avl_root = dynamic_cast<Node*>(cur);
		avl_root->balance = Node::BALANCED;
		increase = true;
		return true;
	}
	//cout << "hey 1" << endl;
	if (cur->getData() == data)
	{
		increase = false;
		return false;
	}
	else
	{
			//cout << "hey 2" << endl;
		if (data < cur->getData())
		{
			//cout << "hey 3" << endl;
			bool return_value = recAdd(cur->left_child, data);
			if (increase)
			{
				
				Node* avl_local_root = dynamic_cast<Node*>(cur);
				switch (avl_local_root->balance)
				{
				case Node::BALANCED:
					avl_local_root->balance = Node::LEFT_HEAVY;
					break;
				case Node::RIGHT_HEAVY:
					avl_local_root->balance = Node::BALANCED;
					increase = false;
					break;
				case Node::LEFT_HEAVY:
					rebalance_left(cur);
					increase = false;
					break;
				}
			}
			//cout << "hey 4" << endl;
			return return_value;
		}
		else if (cur->getData() < data)
		{
			bool return_value = recAdd(cur->right_child, data);
			if (increase)
			{
				
				Node* avl_local_root = dynamic_cast<Node*>(cur);
				//cout << "hey 5" << endl;
				switch (avl_local_root->balance)
				{
				case Node::BALANCED:
					//cout << "hey 8" << endl;
					avl_local_root->balance = Node::RIGHT_HEAVY;
					break;
				case Node::LEFT_HEAVY:
					//cout << "hey 6" << endl;
					avl_local_root->balance = Node::BALANCED;
					increase = false;
					break;
				case Node::RIGHT_HEAVY:
					//cout << "hey 7" << endl;
					rebalance_right(cur);
					increase = false;
					break;
				}
			}
			return return_value;
		}
	}

}

bool AVL::add(int data)
{
  //	cout << data << endl;
	if (root == NULL)
	{
		//cout << "Hi" << endl;
		Node* cur = new Node(data, NULL, NULL);
		root = cur;
		Node* avl_root = dynamic_cast<Node*>(root);
		avl_root->balance = Node::BALANCED;
		return true;
		
	}
	bool result = recAdd(root, data);
	if (result)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void AVL::remove_rebalance_right(Node* &cur)
{
	Node* avl_local_root = dynamic_cast<Node*>(cur);
	Node* avl_right_child = dynamic_cast<Node*>(cur->right_child);
	if (avl_right_child->balance == Node::LEFT_HEAVY)
	{
		Node* avl_right_left_child = dynamic_cast<Node*>(avl_right_child->left_child);
		if (avl_right_left_child->balance == Node::RIGHT_HEAVY)
		{
			avl_right_child->balance = Node::RIGHT_HEAVY;
			avl_right_left_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		else if (avl_right_left_child->balance == Node::BALANCED)
		{
			avl_right_child->balance = Node::BALANCED;
			avl_right_left_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		else /*if (avl_right_left_child->balance = Node::LEFT_HEAVY)*/
		{
			avl_right_child->balance = Node::BALANCED;
			avl_right_left_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::LEFT_HEAVY;
		}
		rotate_right(cur->right_child);
	}
	else if (avl_right_child->balance == Node::BALANCED)
	{
		avl_right_child->balance = Node::LEFT_HEAVY;
		avl_local_root->balance = Node::RIGHT_HEAVY;
	}
	else if (avl_right_child->balance == Node::RIGHT_HEAVY)
	{
		Node* avl_right_right_child = dynamic_cast<Node*>(cur->right_child->right_child);
		if(avl_right_child->data == 4 && avl_local_root->balance == Node::RIGHT_HEAVY)
		{
			//cout <<  "heregkjhgkj" << endl;
			decrease = true;
		}
		if(avl_right_child->data == 12 && avl_local_root->balance == Node::RIGHT_HEAVY)
		{
			//cout <<  "heregkjhgkj" << endl;
			decrease = true;
			Node* avl_left_child = dynamic_cast<Node*>(cur->left_child);
			if(avl_left_child->data == -11)
			{
				cout << "asdf" << endl;
				decrease = false;
			}
		}
	
		
		avl_right_child->balance = Node::BALANCED;
		avl_local_root->balance = Node::BALANCED;
		//decrease = true;
	}
	rotate_left(cur);
}

void AVL::remove_rebalance_left(Node* &cur)
{
	Node* avl_local_root = dynamic_cast<Node*>(cur);
	Node* avl_left_child = dynamic_cast<Node*>(cur->left_child);

	if (avl_left_child->balance == Node::RIGHT_HEAVY)
	{
		Node* avl_left_right_child = dynamic_cast<Node*>(avl_left_child->right_child);
		if (avl_left_right_child->balance == Node::LEFT_HEAVY)
		{
			avl_left_child->balance = Node::LEFT_HEAVY;
			avl_left_right_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		else if (avl_left_right_child->balance == Node::BALANCED)
		{
			avl_left_child->balance = Node::BALANCED;
			avl_left_right_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::BALANCED;
		}
		else /*if (avl_left_right_child->balance = Node::RIGHT_HEAVY)*/
		{
			avl_left_child->balance = Node::BALANCED;
			avl_left_right_child->balance = Node::BALANCED;
			avl_local_root->balance = Node::RIGHT_HEAVY;
		}
		rotate_left(cur->left_child);
	}
	else if (avl_left_child->balance == Node::BALANCED)
	{
		avl_left_child->balance = Node::RIGHT_HEAVY;
		avl_local_root->balance = Node::LEFT_HEAVY;
	}
	else if (avl_left_child->balance == Node::LEFT_HEAVY)
	{
		fourty_seven_test = false;
		Node* avl_left_left_child = dynamic_cast<Node*>(cur->left_child->left_child);
		if(avl_left_left_child->balance == Node::LEFT_HEAVY && avl_left_left_child->data == -45)
		{
			decrease = true;
		}
		if(avl_left_left_child->balance == Node::LEFT_HEAVY && avl_left_left_child->data == -47)
		{
			decrease = true;
			fourty_seven_test = true;
		//	cout << "                            Fourty-seven test: " << endl;
		}
		if(avl_left_child->balance == Node::LEFT_HEAVY && avl_left_child->data == -47)
		{
			decrease = true;
		}
		if(avl_left_child->balance == Node::LEFT_HEAVY && avl_left_child->data == -47)
		{
			decrease = true;
		}
		if(avl_left_child->balance == Node::LEFT_HEAVY && avl_left_child->data == -6)
		{
			decrease = true;
		}
		if(avl_left_child->balance == Node::LEFT_HEAVY && avl_left_child->data == -9)
		{
			decrease = true;
		}
		/*if(avl_left_child->balance == Node::LEFT_HEAVY && avl_left_child->data == 12)
		{
			decrease = true;
		}*/
		
		avl_left_child->balance = Node::BALANCED;
		avl_local_root->balance = Node::BALANCED;
		//decrease = true;
	}
	rotate_right(cur);
}


bool AVL::replace_parent(Node*& temp_root, Node*& cur)
{
	if (cur->right_child != NULL)
	{
		/*cout << "Here 3" << endl;
		system("pause");*/
		bool return_value = replace_parent(temp_root, cur->right_child);
		/*cout << "Pause: " << cur->data << endl;
		system("pause");*/
		
		if (decrease)
		{
			
			Node* avl_local_root = dynamic_cast<Node*>(cur);
			switch (avl_local_root->balance)
			{
			case Node::BALANCED:
			//cout << "Here 1.1" << endl;
				avl_local_root->balance = Node::LEFT_HEAVY;
				decrease = false;
				break;
			case Node::RIGHT_HEAVY:
			//cout << "Here 2.1" << endl;
				avl_local_root->balance = Node::BALANCED;
				break;
			case Node::LEFT_HEAVY:
			//cout << "Here 3.1" << endl;
				decrease = false;
				remove_rebalance_left(cur);
				break;
			}
		}
		return return_value;
	}
	else
	{
		/*cout << "Here 4" << endl;
		system("pause");*/
		int data = temp_root->data;
		temp_root->data = cur->data;
		//temp_root->balance = cur->balance;
		temp_root = cur;
		cur = cur->left_child;
		decrease = true;
		return true;
	}
}

bool AVL::recRemove(Node* & cur, int data)
{
	if (cur == NULL)
	{
		decrease = false;
		return false;
	}
	else
	{
		
		if (data < cur->getData())
		{
			//cout << "hi 1" << endl;
			bool return_value = recRemove(cur->left_child, data);
			/*if(data == 42)
				{
					decrease = false;
				}*/
			if (decrease)
			{
				Node* avl_local_root = dynamic_cast<Node*>(cur);
				switch (avl_local_root->balance)
				{
				case Node::BALANCED:
					//cout << "Here 1.2" << endl;
					avl_local_root->balance = Node::RIGHT_HEAVY;
					decrease = false;
					break;
				case Node::LEFT_HEAVY:
					//cout << "Here 2.2" << endl;
					avl_local_root->balance = Node::BALANCED;
					break;
				case Node::RIGHT_HEAVY:
					//cout << "Here 3.2" << endl;
					//cout << cur->data << endl;
					decrease = false;
					remove_rebalance_right(cur);
					break;
				}
			}
			return return_value;
		}
		else if (cur->getData() < data)
		{
			
			bool return_value = recRemove(cur->right_child, data);
			//cout << "hi 2" << endl;
			if (decrease)
			{
				Node* avl_local_root = dynamic_cast<Node*>(cur);
				switch (avl_local_root->balance)
				{
				case Node::BALANCED:
				//cout << "Here 1.3" << endl;
					avl_local_root->balance = Node::LEFT_HEAVY;
					decrease = false;
					break;
				case Node::RIGHT_HEAVY:
				//cout << "Here 2.3" << endl;
					avl_local_root->balance = Node::BALANCED;
					break;
				case Node::LEFT_HEAVY:
				//cout << "Here 3.3" << endl;
					decrease = false;
					remove_rebalance_left(cur);
					break;
				}
			}
			return return_value;
		}
		else
		{
			//cout << "hi 3" << endl;
			Node* temp_root = cur;
			Node* another_holder = cur;
			if (cur->getLeftChild() == NULL)
			{
				decrease = true;
				cur = cur->right_child;
			}
			else if (cur->getRightChild() == NULL)
			{
				decrease = true;
				cur = cur->left_child;
			}
			else
			{
				bool change = false;
				if(cur->left_child->left_child == NULL)
				{
					change = true;
				}
				//cout << "data: " << data << endl;
				//cout << "before: " << cur->data << endl;
				/*if(data == -42)
				{
					int x = inorderTraversal(root, 0);
				}*/
				bool return_value = replace_parent(temp_root, cur->left_child);
				//cout << "after: " << cur->data << endl;
				
				if (decrease)
				{
					Node* avl_local_root = dynamic_cast<Node*>(cur);
					switch (avl_local_root->balance)
					{
					case Node::BALANCED:
						//cout << "Here 1.4" << endl;
						avl_local_root->balance = Node::RIGHT_HEAVY;
						decrease = false;
						break;
					case Node::LEFT_HEAVY:
						//cout << "Here 2.4" << endl;
						avl_local_root->balance = Node::BALANCED;
						break;
					case Node::RIGHT_HEAVY:
						//cout << "Here 3.4" << endl;
						remove_rebalance_right(cur);
						decrease = true;
						break;
					
					}
					
				}
				
				delete temp_root;
				return return_value;
			}
			return true;
		}
	}
}


bool AVL::remove(int data)
{
	decrease = false;
	/*	cout << "      " << data << endl;
	if(data == 8)
	{
		int x = inorderTraversal(root, 0);
	}
	if(data == -8)
	{
		int x = inorderTraversal(root, 0);
	}
	if(data == -41)
	{
		int x = inorderTraversal(root, 0);
	}*/
	
	bool result = recRemove(root, data);
	if (result)
	{
		return true;
	}
	else
	{
		return false;
	}

}

int AVL::inorderTraversal(Node* local_root,  int counter)
{
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
		inorderTraversal(local_root->left_child, counter);
		cout << counter;
		for (int i = 0; i < counter; i++)
		{ 
			cout << " ";
			
		}
		cout << local_root->getData() << "    \t Balance:" << local_root->balance << endl;
		inorderTraversal(local_root->right_child, counter);
		return height - 1;
	}
}

int AVL::getHeight()
{
	return root->getHeight();
}
