
#include "support.h"


support::support()
{

}

support::~support()
{

}

//¸¨Öúº¯Êý
int support::max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void support::swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void support::print_matrix(int** a, int m, int n)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void support::print_array(int* a, int n)
{
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}