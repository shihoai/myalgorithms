
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

void support_functions::print_matrix(vector<vector<int>> a, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void support_functions::print_array(vector<int> a, int n)
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

void support_functions::print_node(Node *node)
{
	cout << node->getVal() << endl;
}

void support_functions::print_linked_list(Node *node)
{
	while (node) {
		cout << node->getVal() << " ";
		node = node->getNext();
	}
	cout << endl;
}

void support_functions::print_linked_list(Node *node, int n)
{
	for (int i = 0; i < n; i++) {
		cout << node->getVal() << " ";
		node = node->getNext();
	}
	cout << endl;
}

void support_functions::delete_linked_list(Node *node)
{
	if (node == NULL)
		return;

	while (node != NULL && node->getNext() != NULL) {
		Node* temp = node;
		node = node->getNext();
		delete temp;
		temp = NULL;
	}

	delete node;
	node = NULL;

}

int support_functions::genRandom()
{
	return rand() % INT_MAX;
}

vector<int> support_functions::initOneVector(int n)
{
	vector<int>vec(n, 0);
	return vec;
}

vector<vector<int>> support_functions::initTwoVector(int m, int n)
{
	vector<vector<int>> vec(m, vector<int>(n, 0));
	return vec;
}