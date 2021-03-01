#include <iostream>
#include "DataTypes.h"
#include "BinarySearchTree.h"

using namespace std;

//Returns the address of the node created
//Create a node in the bst and stores the newPatient struct in the node.
BTNode * createBTNode (Patient newPatient) {
	BTNode * newNode;
	
	newNode = new BTNode;
	newNode->patient = newPatient;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	
	return newNode;

}


//Returns True if patientID is present in the bst and false otherwise
//Accepts BTNode * root -> the address of the binary search tree
//Accepts int patientID -> an integer value that represents a patientID
bool containsBST (BTNode * root, int patientID) 
{
	
	Patient p;
	
	if (root == NULL)
	{
		return false;
	}
	
	p = root->patient;
	
	if (patientID == p.patientID)
		return true;
	
	if (patientID < p.patientID)
		return containsBST (root->left, patientID);
	else
		return containsBST (root->right, patientID);
}


//Returns the node of the bst containing patientID if it is present and NULL otherwise.
//Accepts BTNode * root -> the address of the bst
//Accepts int patientID -> integer value of the patientID
BTNode * getBST (BTNode * root, int patientID) 
{
	
	bool found=containsBST(root,patientID);

	
	if(found==false)
	{
		cout<<"\nBST EMPTY";
	}
	BTNode * bp=NULL;
	
	if (root->patient.patientID == patientID)
	{

		bp=root;
		return bp;
	}
	
	if (patientID < root->patient.patientID)
		return getBST (root->left, patientID);
	else
		return getBST (root->right, patientID);
}


//Returns the address of the node inserted
//Inserts the newPatient struct in the bst. The key is patientID
BTNode * insertBST (BTNode * root, Patient newPatient) {
	
	BTNode * newNode;
	BTNode * curr;
	
	newNode = createBTNode (newPatient);
	if (root == NULL)
	{
		return newNode;
	}
	
	curr = root;
	
	while (true) {
		Patient p = curr->patient;
		if (newPatient.patientID < p.patientID) {
			if (curr->left == NULL) {
				curr->left = newNode;
				newNode->parent = curr;
				return root;
			}
			curr = curr->left;
		}		
		else {
			if (curr->right == NULL) {
				curr->right = newNode;
				newNode->parent = curr;		
				return root;
			}
			curr = curr->right;
		}
	}
	
}


//Returns the address of the inorder successor of the node, returns NULL if itdoes not exist
//Accepts the address of the node to search for in the bst

BTNode * inOrderSuccessor (BTNode * node) {

	if (node == NULL)
		return NULL;
		
	if (node->right != NULL)
		return treeMinimum (node->right);
		
	BTNode * parent;
	
	parent = node->parent;
	while (parent != NULL && node == parent->right) {
		node = parent;
		parent = parent->parent;
	}
	return parent;	
}


//Returns the address of the node in the bst with the smallest key
//Accepts the address of the root of the bst
BTNode * treeMinimum (BTNode * root) {
	if (root == NULL)
		return NULL;
		
	while (root->left != NULL)
		root = root->left;
	
	return root;
}

