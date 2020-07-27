
//算法
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "publibs.h"
#include "LinkedListNode.h"
class algorithms
{
public:
	algorithms();
	~algorithms();

	//算法
	//字符串相关
	static void lcs(string a,string b);
	static string replaceSpace(string s);

	//矩阵与数组相关
	static void x_print_matrix(vector<vector<int>> a, int n);
	static void right_time_print_matrix(vector<vector<int>> a, int n);
	static void quick_sort(vector<int> a, int left, int right);
	static void three_sum(vector<int> a,int n);
	static int  rand5_to_rand7();
	static bool findInIncreaseTwo(vector<vector<int>> vec, int target);

	//链表相关
	static bool judgeRing(Node *node);
	static Node* cross_node(Node *node);
	static Node* merget_list(Node *l1, Node* n2);
	static Node* RecReverseLink(Node *node);
	static Node* IteReverseLink(Node* node);
	static Node* lastKNode(Node *node,int k);
	static void reorderList(Node* head);
};




#endif // !"algorithms.h"
