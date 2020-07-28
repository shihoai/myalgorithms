
#ifndef SUPPORT_H
#define SUPPORT_H

#include "publibs.h"
#include "LinkedListNode.h"

class support_functions
{
public:

	support_functions();
	~support_functions();

	//基本辅助函数
	static int max(int a, int b);
	static int min(int a, int b);
	static void swap(int& a, int& b);
	static void print_matrix(vector<vector<int>> a);
	static void print_array(vector<int> a, int n);
	static int genRandom();
	static int  random(int a, int b);
	static vector<int> initOneVector(int n);
	static vector<vector<int>> initTwoVector(int m, int n);
	static void randomInitVector(vector<int>& a, int up,int down);
	static void randomInitTwoVector(vector<vector<int>>& a, int up,int down);

	//链表相关
	static void print_node(Node* node);
	static void print_linked_list(Node* node);
	static void print_linked_list(Node* node, int n);
	static void delete_linked_list(Node* node);

};

#endif // !SUPPORT_H
