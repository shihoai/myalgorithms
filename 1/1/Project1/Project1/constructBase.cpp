
#include "constructBase.h"


Node* constructBase::roundLinkList()
{
	Node* head = new Node(-1, NULL);
	Node* temp = head;
	Node* temp_1 = NULL;
	for (int i = 0; i < 20; i++) {
		Node* n1 = new Node(i, NULL);
		temp->setNext(n1);
		temp = temp->getNext();
		if (i == 11) {
			temp_1 = n1;
		}
	}

	temp->setNext(temp_1);
	temp = head->getNext();

	delete head;
	head = NULL;
	return temp;

}

Node* constructBase::generateLinkList(int base, int length)
{
	Node* head = new Node(-1, NULL);
	Node* temp = head;
	for (int i = 0; i < length; i++) {
		Node* n1 = new Node(base * (i + 1), NULL);
		temp->setNext(n1);
		temp = temp->getNext();
	}

	temp = head->getNext();
	delete head;
	head = NULL;
	return temp;
}

Node* constructBase::generateRandLinkList(int length)
{
	Node* head = new Node(-1, NULL);
	Node* temp = head;

	for (int i = 0; i < length; i++) {
		Node* n1 = new Node(support_functions::genRandom(), NULL);
		temp->setNext(n1);
		temp = temp->getNext();
	}

	temp = head->getNext();
	delete head;
	head = NULL;
	return temp;
}

void constructBase::generateIncreaseTwoArray(vector<vector<int>>& matrix)
{
	int x_length = matrix.size();
	int y_length = matrix[0].size();

	for (int i = 0; i < x_length; i++) {
		matrix[i][0] = support_functions::random(i * 200, (i + 1) * 200);
	}

	for (int j = 0; j < y_length; j++) {
		matrix[0][j] = support_functions::random(j * 200, (j + 1) * 200);
	}

	for (int i = 1; i < x_length; i++) {
		for (int j = 1; j < y_length; j++) {
			matrix[i][j] = support_functions::max(matrix[i][j - 1], matrix[i - 1][j]) + support_functions::random(100, 300);
		}
	}
}

vector<int> constructBase::generateArray(int n)
{
	vector<int> a = support_functions::initOneVector(n);
	for (auto& i : a) {
		i = support_functions::random(-10, 10);
	}

	return a;
}

