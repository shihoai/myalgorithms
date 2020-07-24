
#ifndef CONSTRUCTLINKLIST_H
#define CONSTRUCTLINKLIST_H

#include "LinkedListNode.h"
#include "publibs.h"

Node* roundLinkList()
{
	Node* head = new Node(-1,NULL);
	Node* temp = head;
	Node* temp_1 = NULL;
	for (int i = 0; i < 9; i++) {
		Node* n1 = new Node(i, NULL);
		temp->setNext(n1);
		temp = temp->getNext();
		if (i == 4) {
			temp_1 = n1;
		}
	}

	temp->setNext(temp_1);
	temp = head->getNext();

	return temp;

}

#endif // 
