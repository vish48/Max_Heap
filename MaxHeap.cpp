#include <iostream>
#include "DataTypes.h"
#include "MaxHeap.h"
using namespace std;

//Returns the index of the parent node of node i in the heap
int parent(int i) {
	return (i/2);
}


//Returns the index of the left child of node i in the heap
int leftChild(int i) {
	return (2 * i);
}


//Returns the index of the right child of node i in the heap
int rightChild (int i) {
	return (2 * i) + 1;
}


//Assuming that the left and right subtrees of node i are max heaps
//Maitains the max heap property starting at node i
void maxHeapify (Incident A[], int heapSize, int i) {
	int left, right, largest;
	
	left = leftChild(i);
	right = rightChild(i);
	
	if (left <= heapSize && A[left].priority > A[i].priority) 
		largest = left;
	else
		largest = i;
		
	if (right <= heapSize && A[right].priority > A[largest].priority) 
		largest = right;
		
	if (largest != i) {
		Incident temp = A[i];
		A[i] = A[largest];
		A[largest] = temp;
		maxHeapify(A, heapSize, largest);
	}
}


//Given an array A of type Incident where lengthA is the amount of elements in A,
//Converts A into a max heap baed on the priority of each patient
void buildMaxHeap(Incident A[], int lengthA) {

	int heapSize, i;
	
	heapSize = lengthA;
	
	for (i = (lengthA/2); i >= 1; i = i - 1)
			maxHeapify(A, heapSize, i);
}


//Givn an array A of type Incident and lengthA, which is the amount of elements in A,
//Sorts the elements in A based on the priority of the incidents.
void heapSort (Incident A[], int lengthA) {
	
	int heapSize, i;
	
	heapSize = lengthA;

	buildMaxHeap(A, lengthA);
		
	for (i=lengthA; i >= 2; i = i - 1) {
		Incident temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		heapSize = heapSize - 1;
		maxHeapify(A, heapSize, 1);
	}
}
