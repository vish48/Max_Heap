#ifndef _BINARYSEARCHTREE_H
#define _BINARYSEARCHTREE_H

BTNode * createBTNode (Patient newPatient);
bool containsBST (BTNode * root, int patientID);
BTNode * getBST (BTNode * root, int patientID);
BTNode * insertBST (BTNode * root, Patient newPatient);
BTNode * treeMinimum (BTNode * root);
BTNode * inOrderSuccessor (BTNode * node);

#endif
