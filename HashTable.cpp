#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "DataTypes.h"
#include "HashTable.h"

using namespace std;


HashTable * initHT (int sizeTable) 
{
	
	// write code to create a new hash table with the given size, initialize
	// the hash table, and return the address of the hash table created.
	
	HashTable * hash= new HashTable;	
//	cout<<"\nIn the hash function";											//creating variable of type hashtable
	hash->sizeTable=sizeTable;									//setting size of hashtable to be given size
//	cout<<"\nI made the sizeTable "<<sizeTable;
	
	for(int x=0;x<sizeTable;x++)										//initializing hash table of size SizeTable
	{
	//	cout<<"\nin the loop.........x is "<<x;
		hash->elements[x].conditionName=" ";
		hash->elements[x].priority=0;
	}
	
	return hash;													//returning the hashtable
}


int hashCode (int sizeTable, string key) 
{
	int x=0, value=0, ascii=0;
	int length=key.size();
	
	for(x=0;x<length;x++)
	{
		ascii=int(key[x]);
		value=value+(ascii*x);
	}
	
	return value;
}


int containsHT (HashTable * ht, string key, int sizeTable) 
{

	// write code here to determine if the hash table contains the given key.
	
	int x=0, num=0,d=0, original=0;
	num=hashCode(sizeTable,key);
	x=num%sizeTable;
	
	if(ht->elements[x].conditionName==key)
		return ht->elements[x].priority;
	
	original=x;
	d=num%(sizeTable/2);
	x=x+d;
	
	while(x!= original)								//while spot in hashtable is not empty
	{
		if(ht->elements[x].conditionName==key)						//compare key to condition name to see if it matches ans return true	
			return ht->elements[x].priority;;
		x=x+d;
	}	
	return -1;													//searched hashtable and key was not found
}


void insertHT (HashTable * ht, Condition c, int sizeTable) 
{

	// write code here to insert a Condition struct in the hash table.
	// The key is the name of the condition. Linear probing with
	// double hashing should be used to resolve collisions.
	
	int loc=0,num=0,k=0;
	num=hashCode(sizeTable,c.conditionName);						//get the numerical value of the conditionName
	loc=num%sizeTable;												//get the location of hash table to insert the condition struct
	
	if(ht->elements[loc].priority==0)								//if location is empty, insert struct info
	{
		ht->elements[loc].conditionName=c.conditionName;
		ht->elements[loc].priority=c.priority;
	}
	else												//if not empty then use double hashing technique to find next location to check/insert struct info
	{
		k=num%(sizeTable/2);
		loc=loc+k;
		
		while(ht->elements[loc].priority !=0)
		{
			loc=loc+k;
		}
		ht->elements[loc].conditionName=c.conditionName;				//insert struct info when empty location has been found
		ht->elements[loc].priority=c.priority;
	}
}
