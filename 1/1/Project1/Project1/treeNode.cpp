
#include "treeNode.h"


treeNode::treeNode()
{
	val = 0;
	left = NULL;
	right = NULL;
}

treeNode::treeNode(int val, treeNode* left, treeNode* right)
{
	setTreeNode(val, left, right);
}

treeNode::~treeNode()
{

}

void treeNode::setTreeNode(int val, treeNode* left, treeNode* right)
{
	setVal(val);
	setLeft(left);
	setRight(right);
}

void treeNode::setVal(int val)
{
	this->val = val;
}

void treeNode::setLeft(treeNode* left)
{
	this->left = left;
}

void treeNode::setRight(treeNode* right)
{
	this->right = right;
}

int treeNode::getVal()
{
	return val;
}

treeNode* treeNode::getLeft()
{
	return left;
}

treeNode* treeNode::getRight()
{
	return right;
}

treeNode* treeNode::getTreeNode()
{
	return this;
}