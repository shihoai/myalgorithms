#pragma once

#ifndef TREENODE_H
#define TREENODE_H

#include "publibs.h"


class treeNode
{
private:
	int val;
	treeNode* left;
	treeNode* right;

public:
	treeNode();
	treeNode(int val, treeNode* left, treeNode* right);
	~treeNode();
	void setTreeNode(int val, treeNode* left, treeNode* right);
	void setVal(int val);
	void setLeft(treeNode* left);
	void setRight(treeNode* right);
	int getVal();
	treeNode* getLeft();
	treeNode* getRight();
	treeNode* getTreeNode();
};

#endif // !TREENODE_H

