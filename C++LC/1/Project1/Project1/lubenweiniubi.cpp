
#include "publibs.h"
#include "algorithms.h"
#include "support_functions.h"
#include "constructBase.h"



int main()
{
	srand(time(0));

	vector<vector<int>> temp = support_functions::initTwoVector(10, 2);

	for (int i = 0; i < 10; i++) {
		temp[i][0] = support_functions::random(0, 500);
		temp[i][1] = support_functions::random(10,100) + temp[i][0];
	}

	support_functions::print_matrix(temp);
	vector<vector<int>> as = algorithms::mergeInterval(temp);
	cout << endl;
	support_functions::print_matrix(as);


	return 0;
}