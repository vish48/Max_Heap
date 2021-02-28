/*
Changed hash functions insertHT and containsHT to include the parameter sizeTable
FILES MADE TO STOP WHEN 999 AND XXX ARE ENCOUNTERED FOR PATIENT ID AND CONDITION
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "DataTypes.h"
#include "Queue.h"
#include "BinarySearchTree.h"
#include "HashTable.h"
#include "MaxHeap.h"
#include "MaxPriorityQueue.h"

using namespace std;

void menu()
{
	cout<<"\nPatient Management System";
	cout<<"\n----------------------------------------------------------------------\n";
	cout<<"1.	Add New Patient to Patient Database"<<endl;
	cout<<"2.	Add Patient to Priority Queue"<<endl;
	cout<<"3.	Increase Patient Priority"<<endl;
	cout<<"4.	Display Information on Next Patient to be Treated"<<endl;
	cout<<"5.	Treat Highest Priority Patient"<<endl;
	cout<<"6.	Display List of Patients Currently Awaiting Treatment"<<endl;
	cout<<"7.	Display List of Patients Already Treated"<<endl;
	cout<<"8.	Display List of Patients in Patient Database"<<endl;
	cout<<"9.	Add New Conditon and Priority to Hash Table"<<endl;
	cout<<"10.	Quit";
		cout<<"\n----------------------------------------------------------------------\n";
	cout<<"\nPlease enter an option: ";
}

int main () 
{

	// write code here to open Patient.txt and save the data in the binary search tree
	
	ifstream finp;							//opening file and ensuring it is open
	finp.open("Patient.txt");
	
	if(!finp.is_open())
	{
		cout<<"Could not find Patient file";
		return 0;
	}
	
	int PID=0;
	string pname, number;
	finp>>PID;
	
	Patient pinfo;
	BTNode *root=NULL;
	
	while(PID!=999)										//while not end of file
	{
		pinfo.patientID=PID;					//putting patient info into relevant fields
		finp>>pname;
		pinfo.patientName=pname;
		finp>>number;
		pinfo.phone=number;
	
		root=insertBST(root,pinfo);					//calling insertBST function to insert a node into the BST
		finp>>PID;										//reading in next patient ID in file
		
	//	cout<<"\n printing info: "<<PID<<"  "<<pname<<"  "<<number;
	//	cout<<"\nROOT "<<root->patient.patientID<<"  "<<root->patient.patientName<<"  "<<root->patient.phone<<endl;
	}
	
	cout<<"\nI'm done with patient file";
	// write code here to open Incident.txt and save the data in the priority queue
	
	ifstream fini;														//opening file and ensuring it is open
	fini.open("Incident.txt");
	
	if(!fini.is_open())
	{
		cout<<"Could not find Incident file";
		return 0;
	}
	
	int IID=0, priority=0, heapSize=0,count=0;
	string cond;
	fini>>IID;
	
	Incident inc;
	Incident A[1000];
	
	for(count=0;count<1000;count++)
	{
		A[count].patientID=0;
		A[count].condition=" ";
		A[count].priority=0;
	}
	
	while(IID!=999)												//while not the end of file, read in and store data
	{
		inc.patientID=IID;
		fini>>cond;
		inc.condition=cond;
		fini>>priority;
		inc.priority=priority;
		
		heapSize++;
		maxHeapInsert(A,heapSize,inc);						//insert data into priority queue
		fini>>IID;
	}
	
	cout<<"\nI'm done with incident file";
	
//		for(count=1;count<heapSize;count++)
//			{
//				cout<<endl<<A[count].patientID<<"  "<<A[count].condition<<"  "<<A[count].priority;
//			}
	// write code here to open Priority.txt and save the data in the hash table
	
	ifstream finr;										//opening file and ensuring it is open
	finr.open("Priority.txt");
	
	if(!finr.is_open())
	{
		cout<<"Could not find priority file";
		return 0;
	}
	
	string conName;
	int pr=0, sizeTable=701,num=0;
	finr>>conName;
	
	Condition con;
	HashTable *hash;
	hash=initHT(sizeTable);
	
	while(conName!="XXX")											//while not end of file get the data and store in a hash table
	{
		con.conditionName=conName;
		finr>>pr;
		con.priority=pr;
		
		num++;
		insertHT(hash,con,sizeTable);
		finr>>conName;
	}

	cout<<"\nI'm done with priority file";
	// Now, write code to display the menu and perform the operations for Options 1-9.
	
	Queue *queue=initQueue();				//for patients finished with treatment
	//Incident iqueue;
	
	int opt=0,pty=0;						//getting user menu option
	menu();
	cin>>opt;
	
	int pid=0, patientpr=0,np=0,i=0,x=0, newpriority=0,t=0;
	string name,pnum,condition,newcondition;
	Patient npinfo;
	Incident highest;
	Condition c;
	BTNode *ppatient;
	bool found;
	
	while(opt!=10)
	{
		if(opt==1)
		{
			cout<<"\nEnter new patient ID: ";
			cin>>pid;
			npinfo.patientID=pid;
			
			cout<<"\nEnter new patient name: ";
			cin>>pname;
			npinfo.patientName=pname;
			
			cout<<"\nEnter new patient phone: ";
			cin>>pnum;
			npinfo.phone=pnum;
			
			ppatient=insertBST(root,npinfo);
			cout<<"\nNew patient has been added."<<endl;
			
			system("pause");
			system("CLS");
			
			menu();
			cin>>opt;
		}
		
		if(opt==2)
		{
			heapSize++;
				
			cout<<"\nEnter patient ID: ";
			cin>>pid;
			
			cout<<"\nEnter patient condition: ";
			cin>>condition;
			
			cout<<"\nEnter patient priority: ";
			cin>>pty;
			
			found=containsBST(root,pid);
			
			if(found== false)
			{
				cout<<"\nPatient not found! Please select option 1 to enter patient into the database first before selecting this option."<<endl;
			}
			else
			{
				Incident report;	
				report.patientID=pid;
				report.condition=condition;
				report.priority=pty;
				
//				patientpr=containsHT(hash,condition,sizeTable);
				maxHeapInsert(A,heapSize, report);
				cout<<"\nPatient has been added to priority queue."<<endl;
			}
			
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
		
		if(opt==3)					//how to get i???
		{
			cout<<"\nEnter patient ID: ";
			cin>>pid;
			
			cout<<"\nEnter patient new priority: ";	
			cin>>np;
			
			found=containsBST(root,pid);
			
			if(found==false)
			{
				cout<<"\nPatient not found! Please select option 1 to enter patient into database first before selecting this option."<<endl;
			}
			else
			{
				for(x=0;x<heapSize;x++)
				{
					if(A[x].patientID==pid)
					{
						i=x;
//						cout<<"FOUND THE SPOT";	
					}
				}
				
				if(A[i].priority>np)
				{
					cout<<"Current value is larger than new priority";
				}
				else
				{
					heapIncreaseKey(A,i,np);
					cout<<"\nPatient's priority has been increased."<<endl;
	//				cout<<"PROOF: "<<A[i].patientID<<"  "<<A[i].priority<<end;
				}
			}
			
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
		
		if(opt==4)							//maxHeapInsert not working, ranking priority needs to be done somewhere
		{		
			highest=heapMaximum(A);

			if(highest.priority==0)
			{
				cout<<"\nThere is no highest priority patient."<<endl;
			}
			else
			{
				cout<<"\nInformation on highest priority patient: "; 
				cout<<"\nPatient ID: "<<highest.patientID;
				cout<<"\nPatient condition: "<<highest.condition;
				cout<<"\nPatient priority: "<<highest.priority<<endl;
			}
				
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
		
		if(opt==5)
		{
			cout<<"\nTreating highest priority patient: ";
			highest=heapMaximum(A);
			
			if(highest.priority==0)
			{
				cout<<"\nThere is no highest priority patient."<<endl;
			}
			else
			{ 
				cout<<"\nPatient ID: "<<highest.patientID;
				cout<<"\nPatient condition: "<<highest.condition;
				cout<<"\nPatient priority: "<<highest.priority<<endl;
			}
			
			highest=heapExtractMax(A,heapSize);
			enqueue(queue,highest);
			
			cout<<"\nPatient has been treated!"<<endl;
			
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;	
		}
		
		if(opt==6)				//getBST function not working
		{
			cout<<"\nList of patients currently awaiting treatment: ";
			cout<<"\nNumber \t\t Name \t\t\t Condition \t\t Priority ";
			cout<<"\n------------------------------------------------------------------------------------";
			
			for(t=1;t<heapSize+2;t++)
			{
				if(A[t].patientID!=0)
				{
					ppatient=getBST(root,A[t].patientID);
					name=ppatient->patient.patientName;
					cout<<endl<<t<<". "<<A[t].patientID<<setw(20)<<name<<setw(27)<<A[t].condition<<setw(15)<<A[t].priority;
				}
			}
			
			cout<<endl;
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
		
		if(opt==7)
		{
			cout<<"\nList of Patients Already Treated: ";
			cout<<"\nName \t\t\t Condition \t\t Priority";
			cout<<"\n--------------------------------------------------------------";
			
			QueueNode *curr=queue->top;
		
			while(curr!=NULL)
			{
				ppatient=getBST(root,curr->data.patientID);
				cout<<endl<<ppatient->patient.patientName<<setw(30)<<curr->data.condition<<setw(15)<<curr->data.priority;
				curr=curr->next;
			}
		
			cout<<endl<<endl;
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
		
		if(opt==8)			//have to use some sort of traversal??
		{
			cout<<"\nList of patients in patient database: ";
			cout<<"\n--------------------------------------------------------";
			cout<<"\nID \t\t Name \t\t Phone ";
			
			ppatient=root;	
			while(ppatient!=NULL)
			{
				cout<<endl<<ppatient->patient.patientID<<"\t\t"<<ppatient->patient.patientName<<"\t"<<ppatient->patient.phone;
				ppatient=inOrderSuccessor(ppatient);
			}
	
			cout<<endl;
			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
		
		if(opt==9)
		{	
			cout<<"\nEnter new condition: ";
			cin>>newcondition;
			cout<<"\nEnter new priority: ";
			cin>>newpriority;
			
			c.conditionName=newcondition;
			c.priority=newpriority;
			insertHT(hash,c,sizeTable);
			
			cout<<"\nNew condition and priority added to hashtable."<<endl;

			system("pause");
			system("CLS");
				
			menu();
			cin>>opt;
		}
	}	
	
	cout<<"\nEnd of Program";
	finp.close();				//closing files
	fini.close();
	finr.close();
	return 0;
}
