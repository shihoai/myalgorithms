
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
	static void swap(int& a, int& b);
	static void print_matrix(int** a, int m, int n);
	static void print_array(int* a, int n);
	static int random(int a, int b);

	//链表相关
	static void print_node(Node* node);
	static void print_linked_list(Node* node);
	static void print_linked_list(Node* node, int n);

};

#endif // !SUPPORT_H
