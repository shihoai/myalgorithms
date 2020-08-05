
#include "publibs.h"
#include "algorithms.h"
#include "support_functions.h"
#include "constructBase.h"



int main()
{
	srand(time(0));
	string a;
	string b;

	while (cin >> a >> b) {
		cout<<algorithms::compareVersion(a, b)<<endl;
	}


	return 0;
}