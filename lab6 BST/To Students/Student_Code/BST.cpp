#include "BST.h"


BST::BST()
{
	root = NULL;
}


BST::~BST()
{
	clear();
}

NodeInterface * BST::getRootNode()
{
	return root; 
}
// Need & to effectively change the value instead of just a copy
/*(NodeInterface* &cur, int data)
{
	//NodeInterface * cur = temp_cur; 
	if (cur == NULL)
	{
		cout << "1Added: " << data << endl;
		cur = new Node(data, NULL, NULL);
		return true;
	}
	if (cur->getData() == data)
	{
		cout << "Did not add Because of dulpicate \n";
		return false;
	}

	if (data < cur->getData())
	{
		cout << "left Tree \n";
		return recAdd(cur->getLeftChild(), data);


		if (cur->getLeftChild() == NULL)
		{
			//cur = cur->getLeftChild();
			cout << "2Added: " << data << endl;
			*cur->getLeftChild() = Node(data, NULL, NULL);
			return true;
		}
	
		else if (recAdd(left_child, data))
		{
			cout << "recursive left" << endl;
			return true;
		}
		else
		{
			return false;
		}
		
	}
	
	else
	{
		cout << "Right Tree \n";

		if (recAdd(right_child, data))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
		
}*/
bool BST::recAdd(Node* &cur, int data)
{
	if (cur == NULL)
	{
		cur = new Node(data, NULL, NULL);
		return true;
	}
	if (cur->getData() == data)
	{
		return false;
	}

	else 
	{
		if (data < cur->getData())
		{
			return recAdd(cur->left_child, data);
		}
		else if (cur->getData()<data)
		{
			return recAdd(cur->right_child, data);
		}
		else { return false; }
	}

}

bool BST::add(int data)
{
	
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

/*Three Case:
1-Only Right Child
-Promote curr to the right child
-store the variable in temp variable and
then assign cur to child node(If done by reference this updates the parent's link)
2-Only Left Child
-Promote curr to the Left Child
3-Has both Children
-Replace with inorder predecesor (smaller but biggest)
-One step left, go as far right as possible
-Call replacement function on pointer to iop
*/
void replace_parent(Node*& temp_root, Node*& cur)
{
	if (cur->right_child != NULL)
	{
		replace_parent(temp_root, cur->right_child);
	}
	else
	{
		temp_root->data = cur->data;
		temp_root = cur;
		cur = cur->left_child;
	}
}

bool BST::recRemove(Node* & cur, int data)
{
	if (cur == NULL)
	{
		return false;
	}
	else
	{
		if (data < cur->getData())
		{
			return recRemove(cur->left_child, data);
		}
		else if (cur->getData() < data)
		{
			return recRemove(cur->right_child, data);
		}
		else
		{
			Node* temp_root = cur;
			if (cur->getLeftChild() == NULL)
			{
				cur = cur->right_child;
			}
			else if (cur->getRightChild() == NULL)
			{
				cur = cur->left_child;
			}
			else
			{
				replace_parent(temp_root, cur->left_child);
			}
			delete temp_root;
			return true;
		}
	}
}

bool BST::remove(int data)
{
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

void BST::clear()
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

bool BST::inorderTraversal(NodeInterface* local_root)
{
	if (local_root == NULL)
	{
		return true;
	}
	else
	{
		inorderTraversal(local_root->getLeftChild());
		cout << local_root->getData() << endl;
		inorderTraversal(local_root->getRightChild());
		return true;
	}

	

}