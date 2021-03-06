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