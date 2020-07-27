
#include "publibs.h"
#include "algorithms.h"
#include "support_functions.h"
#include "constructBase.h"



int main()
{
	srand(time(0));
	Node *head = constructBase::generateRandLinkList(9);
	support_functions::print_linked_list(head);
	algorithms::reorderList(head);
	support_functions::print_linked_list(head);
	return 0;
}