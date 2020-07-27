
#ifndef CONSTRUCTBASE_H
#define CONSTRUCTBASE_H

#include "publibs.h"
#include "support_functions.h"

class constructBase
{
public:
	static Node* roundLinkList();
	static Node* generateLinkList(int base, int length);
	static Node* generateRandLinkList(int length);
	static void generateIncreaseTwoArray(vector<vector<int>>& matrix);

};

#endif
