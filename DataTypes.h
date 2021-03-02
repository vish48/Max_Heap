#ifndef _DATATYPES_H
#define _DATATYPES_H

#include <iostream>
using namespace std;

//Definitions of structs that will be used in the .cpp files
struct Condition {
	string conditionName;
	int priority;
};

struct Patient {
	int patientID;
	string patientName;
	string phone;
};

struct Incident {
	int patientID;
	string condition;
	int priority;
};
   
struct BTNode {
	Patient patient;
	BTNode * left;
	BTNode * right;
	BTNode * parent;
};

struct QueueNode {
	Incident data;
	QueueNode * next;	
};

#endif
