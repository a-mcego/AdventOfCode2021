#include "global.h"

void day02()
{
	vector<pair<string, int>> v;
	ifstream ifs("2.txt");

	string command;
	int n;
	while (ifs >> command)
	{
		ifs >> n;
		v.push_back(make_pair(command, n));
	}

	{
		long long int position = 0, depth = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].first == "forward")
				position += v[i].second;
			if (v[i].first == "up")
				depth -= v[i].second;
			if (v[i].first == "down")
				depth += v[i].second;
		}
		cout << position * depth << endl;
	}

	{
		long long int aim = 0, position = 0, depth = 0;
		for (int i = 0; i < v.size(); ++i)
		{
			if (v[i].first == "forward")
				position += v[i].second, depth += v[i].second * aim;
			if (v[i].first == "up")
				aim -= v[i].second;
			if (v[i].first == "down")
				aim += v[i].second;
		}
		cout << position * depth << endl;
	}

}