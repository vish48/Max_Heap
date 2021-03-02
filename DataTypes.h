#ifndef _DATATYPES_H
#define _DATATYPES_H

#include <iostream>
using namespace std;

//DEFINITIONS OF STRUCTS THAT WILL BE USED IN THE .CPP FILES
//A STRUCT CONTAINING CONDITIONS AND PRIORITUES WHICH ARE STORED IN A HASHTABLE
struct Condition {
	string conditionName;
	int priority;
};
//A STRUCT CONTAINING PATIENT INFORMATION WHICH IS STORED IN THE PATIENT DATABASE(BINARY SEARCH TREE) 
struct Patient {
	int patientID;
	string patientName;
	string phone;
};
//A STRUCT CONTAINING INFORMATION ABOUT A PATIENT TO BE TREATED. THE MAX PRIORITY QUEUE AND THE QUEUE OF
//PATIENTS ALREADY TREATED CONTAIN DATA TYPE INCIDENT.
struct Incident {
	int patientID;
	string condition;
	int priority;
};
//A NODE IN THE BINARY SEARCH TREE (WHICH STORES DATA OF TYPE PATIENT)
struct BTNode {
	Patient patient;
	BTNode * left;
	BTNode * right;
	BTNode * parent;
};
//A NODE IN THE QUEUE OF PATIENTS ALREADY TREATED
struct QueueNode {
	Incident data;
	QueueNode * next;	
};

#endif
