#include <iostream>
#include "DataTypes.h"
#include "MaxHeap.h"
#include "MaxPriorityQueue.h"
using namespace std;


void maxHeapInsert(Incident A[], int heapSize, Incident newIncident) 
{

	// Write code to insert newIncident in the max priority queue.
	// It is stored in array A based on its priority.
/*	heapSize++;
	
	if(A[1].priority==0)			//if heap is empty then insert info
	{								
		A[1].patientID=newIncident.patientID;
		A[1].condition=newIncident.condition;
		A[1].priority=newIncident.priority;
		//cout<<"\nSUCCESSFUL!";
	}
	else
	{	
		int index=1;-
		
		while(A[index].priority !=0)			//finding next empty location in array
			index++;
												//inserting into next empty location
		A[index].patientID=newIncident.patientID;
		A[index].condition=newIncident.condition;
		A[index].priority=newIncident.priority;
		
		
		maxHeapify(A,heapSize,index);		//calling maxheapify function to maintain priority queue properties
	//	cout<<"\nSUCCESSFUL!";
	}			
	*/
	
	heapSize++;
	A[heapSize].patientID=newIncident.patientID;
	A[heapSize].condition=newIncident.condition;
	A[heapSize].priority=INT_MIN;
	heapIncreaseKey(A,heapSize,newIncident.priority);
//	cout<<"\nINSERTED "<<newIncident.priority;
	
}



Incident heapMaximum (Incident A[]) 
{
	// Write code to find and return the highest priority element 
	// in the max priority queue stored in array A.
	
	Incident i;								//highest priority would be in first location of array bc max priority queue
	i.patientID=A[1].patientID;
	i.condition=A[1].condition;
	i.priority=A[1].priority;
	return i;
}



Incident heapExtractMax (Incident A[], int heapSize) 
{
	// Write code to remove and return the highest priority element 
	// in the max priority queue stored in array A.
	
	Incident max;												//getting highest priority element
	max=heapMaximum(A); 
	
	int last=0,a=0,b=heapSize, prev=0;													//getting last element in priority queue
	last= A[heapSize].priority;										
//	cout<<"\nLAST IS "<<last<<" for patient "<<A[heapSize].patientID;
	
	Incident temp;												//swapping last and highest priority element
	temp.patientID=max.patientID;
	temp.condition=max.condition;
	temp.priority=max.priority;
	
//	cout<<"\nHEAPSIZE ELEMENT "<<heapSize<<"  "<<A[heapSize].priority<<" with ID"<<A[heapSize].patientID;
	max.patientID=A[heapSize].patientID;
	max.condition=A[heapSize].condition;
	max.priority=A[heapSize].priority;
	
	A[heapSize+1].patientID=temp.patientID;
	A[heapSize+1].condition=temp.condition;
	A[heapSize+1].priority=temp.priority;
	
	for(a=2;a<=heapSize;a++)
	{
		prev=a-1;
//		b=a+1;
		
		A[prev].patientID=A[a].patientID;
		A[prev].condition=A[a].condition;
		A[prev].priority=A[a].priority;
		
//		A[a].patientID=A[b].patientID;
//		A[a].condition=A[b].condition;
//		A[a].priority=A[b].priority;
		
	}
		
//	cout<<"\nA IS "<< a<<"  Deleting loc a";
	A[heapSize].patientID=0;
	A[heapSize].condition=" ";
	A[heapSize].priority=0;
		
	A[a].patientID=0;
	A[a].condition=" ";
	A[a].priority=0;
		
//	max.patientID=0;
//	max.condition=" ";
//	max.priority=0;	
		
	heapSize--;	
	maxHeapify(A,heapSize,1);									//heapifying the array
	return temp;			
}



void heapIncreaseKey(Incident A[], int i, int newPriority) 
{

	// Write code to increase the value of element i's priority to the 
	// new value, newPriority, where newPriority must be greater than
	// element i's current priority.
	
/*	A[i].priority=newPriority;
	maxHeapify(A,heapSize,1);
	
	return;
*/
  

	A[i].priority=newPriority;
	Incident temp;
	int j=0;
	j=i-1;
	
	while( (j>=1) )//A[i].priority> A[j].priority)
	{
	
		if(A[i].priority>A[j].priority)
		{
	//		cout<<"\nI'M INCREASING";
			temp.patientID=A[i].patientID;
			temp.condition=A[i].condition;
			temp.priority=A[i].priority;
			
			A[i].patientID=A[j].patientID;
			A[i].condition=A[j].condition;
			A[i].priority=A[j].priority;
			
			A[j].patientID=temp.patientID;
			A[j].condition=temp.condition;
			A[j].priority=temp.priority;
		}
		j--;
		i--;
	//	i=j;
	//	j=j/2;
	}
}



