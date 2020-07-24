
#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

#include "publibs.h"

class Node
{
private:
	Node* next;
	int val;

public:
	Node();
	Node(int val, Node *next);
	Node(const Node & node);
	~Node();
	void setNode(int val, Node *next);
	void setVal(int val);
	void setNext(Node* next);
	int getVal();
	Node* getNext();
	Node* getNode();

	bool operator==(const Node& node);
	bool operator!=(const Node& node);
};

#endif