
#include "support_functions.h"

support_functions::support_functions()
{

}

support_functions::~support_functions() 
{

}

//基本辅助函数
int support_functions::max(int a, int b)
{
	if (a > b)
		return a;

	return b;
}


void support_functions::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void support_functions::print_matrix(int** a, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void support_functions::print_array(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int support_functions::random(int a, int b)
{
	return rand() % (b - a) + a;
}


//链表相关

void support_functions::print_node(Node* node)
{
	cout << node->getVal() << endl;
}

void support_functions::print_linked_list(Node* node)
{
	while (node) {
		cout << node->getVal() << " ";
		node = node->getNext();
	}
	cout << endl;
}

void support_functions::print_linked_list(Node* node, int n)
{
	for (int i = 0; i < n; i++) {
		cout << node->getVal() << " ";
		node = node->getNext();
	}
	cout << endl;
}