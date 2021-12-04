#include "global.h"

vector<int> getcounts(vector<string>& lines)
{
	vector<int> counts = vector<int>(lines[0].length(), 0);
	for (string s : lines)
	{
		for (int place = 0; place < s.length(); ++place)
		{
			char c = s[place];
			if (c == '0')
				counts[place] -= 1;
			else
				counts[place] += 1;
		}
	}
	return counts;
}

void day03()
{
	vector<string> lines = GetLines("3.txt");
	
	{
		vector<int> counts = getcounts(lines);

		int gamma = 0, epsilon = 0;
		for (int count : counts)
		{
			gamma <<= 1, epsilon <<= 1;
			if (count > 0)
				gamma |= 1;
			else if (count < 0)
				epsilon |= 1;
			else
				cout << "Unspecified." << endl;
		}

		cout << gamma * epsilon << endl;
	}


	int oxygen=0, co2=0;
	{
		vector<string> oxygens = lines;
		int count_position = 0;
		while (oxygens.size() > 1)
		{
			vector<int> counts = getcounts(oxygens);
			char chosen;
			if (counts[count_position] >= 0)
				chosen = '1';
			else
				chosen = '0';

			vector<string> new_oxygens;
			for (string o : oxygens)
				if (o[count_position] == chosen)
					new_oxygens.push_back(o);

			oxygens = new_oxygens;
			++count_position;
		}
		for (char c : oxygens[0])
			oxygen = (oxygen << 1) + (c == '1' ? 1 : 0);
	}
	{
		vector<string> co2s = lines;
		int count_position = 0;
		while (co2s.size() > 1)
		{
			vector<int> counts = getcounts(co2s);
			char chosen;
			if (counts[count_position] >= 0)
				chosen = '0';//0 and 1 in different order than in the oxygen
			else
				chosen = '1';

			vector<string> new_co2s;
			for (string o : co2s)
				if (o[count_position] == chosen)
					new_co2s.push_back(o);

			co2s = new_co2s;

			++count_position;

		}
		for (char c : co2s[0])
			co2 = (co2 << 1) + (c == '1' ? 1 : 0);
	}
	cout << oxygen * co2 << endl;
}