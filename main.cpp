#include <iostream>
#include <cstdlib>
#include "bts.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	
 int tree[16]= {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
 bts mt;
 cout<< "print in order before adding nos...."<<endl;
 mt.printInOrder();
 for (int i = 0; i < 16; i++)
 {
 	mt.addLeaf(tree[i]);
 }
 cout<< "print in order after adding nos...."<<endl;

 mt.printInOrder();
 cout<<endl;

for (int i = 0; i < 16; i++)
 {
 	mt.printChildern(tree[i]);
 	cout<<endl;

 }

	return 0;
}