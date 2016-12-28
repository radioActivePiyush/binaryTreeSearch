#include <iostream>
#include <cstdlib>
#include "bts.h"

using namespace std;

bts::bts()
{
	root = NULL;
}


bts::node* bts::createLeaf(int key)
{ 
	node* n = new node;
	n->key = key;//first inside node sec passed 
	n->right = NULL;
	n->left = NULL;
	return n;
}
void bts::addLeaf(int key)
{
	addLeafPrivate(key,root);

}
void bts::addLeafPrivate(int key,node* ptr)
{
	if (root == NULL)
	{
		root = createLeaf(key);
	}
	else if (key < ptr->key)	
	{
		if (ptr->left != NULL)
		{
			addLeafPrivate(key,ptr->left);
		}
		else
		{
			ptr->left = createLeaf(key);
		}
	}
	else if (key > ptr->key)	
	{
			if (ptr->right != NULL)
			{
				addLeafPrivate(key,ptr->right);
			}
			else
			{
				ptr->right = createLeaf(key);
			}
	}
	else
	{
		cout <<"the key is taken"<<endl;
	}

}

void bts::printInOrder()
{
	printInOrderPrivate(root);
}

void bts::printInOrderPrivate(node* ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)	//step 1
		{
			printInOrderPrivate(ptr->left);
		}

		cout<<ptr->key<<" "; // step 2

		if (ptr->right != NULL)	//step 3
		{
			printInOrderPrivate(ptr->right);
		}
		
	}
	else
	{
		cout<<"the tree is empty"<<endl;
	}
}

bts::node* bts::returnNode(int key)
{
	return returnNodePrivate(key, root);
}
bts::node* bts::returnNodePrivate(int key,node* ptr )
{
	if (ptr != NULL)
	{
		if (ptr->key == key )
			return ptr;		
		
		else
		{
			if (key< ptr->key)
				return returnNodePrivate(key,ptr->left);
			else
				return returnNodePrivate(key,ptr->right);
		}

	}
	else
	{
		return NULL;
	}
}
int bts::returnRootKey()
	{
		if (root != NULL)
		{
			return root->key;
		}						//check to make sure that root is 
		else					//is pointing to some node						
		{
			return -1000;
		}
	}
void bts::printChildern(int key)
{
	node* ptr = returnNode(key);

	if (ptr != NULL)
	{
		cout<<"parent node = "<<ptr->key<<endl;

		ptr->left == NULL?
		cout<< "left child is null \n":
		cout<< "left child = "<< ptr->left->key <<endl;

		ptr->right == NULL?
		cout<< "right child is null\n":
		cout<< "right child = "<< ptr->right->key <<endl;		
	}
	else
	{
		cout<<"the key "<<key <<" is not in the tree"<<endl;
	}
}
