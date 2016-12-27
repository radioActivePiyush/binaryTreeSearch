class bts
{
private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;
	node* createLeaf(int key);
	node* returnNodePrivate(int key,node* ptr);
	void addLeafPrivate(int key,node* ptr);			
	void printInOrderPrivate(node* ptr);

public:
	bts();
	void addLeaf(int key);
	void printInOrder();
	
	node* returnNode(int key);
	
	
};