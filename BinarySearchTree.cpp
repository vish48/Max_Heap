#include <iostream>
#include "DataTypes.h"
#include "BinarySearchTree.h"

using namespace std;


BTNode * createBTNode (Patient newPatient) {
	BTNode * newNode;
	
	newNode = new BTNode;
	newNode->patient = newPatient;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	
	return newNode;

}



bool containsBST (BTNode * root, int patientID) 
{
	
	Patient p;
	
	if (root == NULL)
	{
//		cout<<"BST IS EMPTY";
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



BTNode * getBST (BTNode * root, int patientID) 
{
	
	// Write code here to find and return the node in the BST containing the key, patientID.
	//	HINT: It is similar to containsBST.
	
	bool found=containsBST(root,patientID);
//	cout<<"\nGOT OUT OF CONTAINS ";
	
	if(found==false)
	{
		cout<<"\nBST EMPTY";
//		return NULL;
	}
	BTNode * bp=NULL;
	
	if (root->patient.patientID == patientID)
	{
//		cout<<"\nI GOT SOMETHING";
		bp=root;
		return bp;
	}
	
	if (patientID < root->patient.patientID)
		return getBST (root->left, patientID);
	else
		return getBST (root->right, patientID);
}



BTNode * insertBST (BTNode * root, Patient newPatient) {
	
	BTNode * newNode;
	BTNode * curr;
	
	newNode = createBTNode (newPatient);
//	cout<<"\nNEWNODE IS "<<newNode->patient.patientID<<"  "<<newNode->patient.patientName<<"  "<<newNode->patient.phone<<endl;
	if (root == NULL)
	{
//		cout<<"I COMPLETED IT";
		return newNode;
	}
	
	curr = root;
	
	while (true) {
		Patient p = curr->patient;
		if (newPatient.patientID < p.patientID) {
			if (curr->left == NULL) {
				curr->left = newNode;
				newNode->parent = curr;
//				cout<<"I COMPLETED IT";
				return root;
			}
			curr = curr->left;
		}		
		else {
			if (curr->right == NULL) {
				curr->right = newNode;
				newNode->parent = curr;	
//				cout<<"I COMPLETED IT";			
				return root;
			}
			curr = curr->right;
		}
	}
	
}



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



BTNode * treeMinimum (BTNode * root) {
	if (root == NULL)
		return NULL;
		
	while (root->left != NULL)
		root = root->left;
	
	return root;
}

