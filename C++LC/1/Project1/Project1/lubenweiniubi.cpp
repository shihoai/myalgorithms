
#include "publibs.h"
#include "algorithms.h"
#include "support_functions.h"
#include "constructBase.h"



int main()
{
	srand(time(0));
	int n;
	while (cin >> n) {
		vector<int>a = support_functions::initOneVector(n);
		support_functions::inputArray(a);
		cout << algorithms::findMoreInt(a) << endl;
	}

	return 0;
}