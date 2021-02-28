#include <iostream>
#include <cstdlib>

#include "NodeTypes.h"
#include "BinaryTree.h"
#include "Stack.h"
#include "Queue.h"


using namespace std;


void preOrder (BTNode * root) 
{
	Stack *s=initStack();
	BTNode * curr = root;
	bool end=false;
	
	while(!end)				//while true
	{
		while(curr!= NULL)
		{
			cout<< curr->data<<"  ";			//print data, push on stack and assign curr to left of node
			push(s,curr);
			curr=curr->left;
		}
		if(isEmptyStack(s))					//if empty change end to true to exit outer while loop
			end=true;
		else								//if not empty pop from stack and assign curr to right of node
		{
			curr=pop(s);
			curr=curr->right;
		}
	}
}
