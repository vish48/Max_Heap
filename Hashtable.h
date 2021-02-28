#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>
	using namespace std;

#include "DataTypes.h"

#define MAX_ELEMENTS 1000
#define EMPTY ""

struct HashTable {
	Condition elements [MAX_ELEMENTS];
	int sizeTable;
};
	
HashTable * initHT (int sizeTable);
void insertHT (HashTable * ht, Condition c, int sizeTable);
int containsHT (HashTable * ht, string key, int sizeTable);

#endif
