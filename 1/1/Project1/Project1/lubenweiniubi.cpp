
#include "publibs.h"
#include "algorithms.h"
#include "support_functions.h"
#include "coustructLinkList.h"





int main()
{
	Node *head = roundLinkList();
	support_functions::print_linked_list(head, 9);

	Node* answer = algorithms::cross_node(head);
	support_functions::print_node(answer);
	return 0;
}