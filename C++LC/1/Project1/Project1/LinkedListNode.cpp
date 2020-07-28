
#include "LinkedListNode.h"


Node::Node()
{
	next = NULL;
	val = 0;
}

Node::Node(int val,Node* next)
{
	setNode(val,next);
}

Node::Node(const Node& node)
{
	next = node.next;
	val = node.val;
}

Node::~Node()
{

}

void Node::setNode(int val,Node* next)
{
	setVal(val);
	setNext(next);
}

void Node::setVal(int val)
{
	this->val = val;
}

void Node::setNext(Node* next)
{
	this->next = next;
}

int Node::getVal()
{
	return val;
}

Node* Node::getNext()
{
	return next;
}

Node* Node::getNode()
{
	return this;
}

bool Node::operator==(const Node& node)
{
	if (val == node.val && next == node.next)
		return true;

	return false;
}

bool Node::operator!=(const Node& node)
{
	if (val != node.val || next != node.next)
		return true;

	return false;
}