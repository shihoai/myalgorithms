
#include "publibs.h"
#include "algorithms.h"
#include "support_functions.h"
#include "constructBase.h"



int main()
{
	srand(time(0));
	vector<int> b = constructBase::generateArray(15);
	support_functions::print_array(b,15);
	int c = algorithms::maxSumArray(b);
	cout << c << endl;
	return 0;
}