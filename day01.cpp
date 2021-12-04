#include "global.h"

void day01()
{
	vector<int> v;
	ifstream ifs("1.txt");

	int n;
	while (ifs >> n)
	{
		v.push_back(n);
	}

	int count = 0;
	for (int i = 1; i < v.size(); ++i)
	{
		if (v[i] > v[i - 1])
			count += 1;
	}
	cout << count << endl;


	int count2 = 0;
	for (int i = 3; i < v.size(); ++i)
	{
		if (v[i] > v[i - 3])
			count2 += 1;
	}
	cout << count2 << endl;
}
