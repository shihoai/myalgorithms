
//Ëã·¨
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "publibs.h"
#include "LinkedListNode.h"
class algorithms
{
public:
	algorithms();
	~algorithms();



	//Ëã·¨
	static void lcs(string a,string b);
	static void x_print_matrix(int** a, int n);
	static void right_time_print_matrix(int** a, int n);
	static void quick_sort(int* a, int left, int right);
	static void three_sum(int* a,int n);
	static bool judgeRing(Node *node);
	static Node* cross_node(Node* node);
	
};




#endif // !"algorithms.h"
