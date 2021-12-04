#include "global.h"

const vector<uint> patterns =
{
	0b00000'00000'00000'00000'11111,
	0b00000'00000'00000'11111'00000,
	0b00000'00000'11111'00000'00000,
	0b00000'11111'00000'00000'00000,
	0b11111'00000'00000'00000'00000,
	0b00001'00001'00001'00001'00001,
	0b00010'00010'00010'00010'00010,
	0b00100'00100'00100'00100'00100,
	0b01000'01000'01000'01000'01000,
	0b10000'10000'10000'10000'10000,
};

struct Board
{
	vector<int> numbers;
	uint checked=0;
	bool already_won=false;

	void mark_number(int n)
	{
		for (int i = 0; i < numbers.size(); ++i)
			if (numbers[i] == n)
				checked |= (1<<i);
	}

	int get_points()
	{
		int pts=0;
		for (int i = 0; i < numbers.size(); ++i)
		{
			if (checked & (1 << i))
				continue;
			pts += numbers[i];
		}
		return pts;
	}

	int has_win()
	{
		for (int pattern : patterns)
		{
			if ((checked & pattern) == pattern)
			{
				already_won = true;
				return true;
			}
		}
		return false;
	}
};

void day04()
{
	ifstream file("4.txt");
	string randnums_str;
	file >> randnums_str;

	vector<int> randnums = FromString<int>(split(randnums_str,","));

	vector<Board> boards;

	while (true)
	{
		vector<int> nums = readthings<int,25>(file);
		if (nums.empty())
			break;
		boards.push_back(Board{nums});
	}

	int total_wins = 0;
	for (int randnum : randnums)
	{
		for (Board& board : boards)
		{
			if (board.already_won)
				continue;
			board.mark_number(randnum);
			if (board.has_win())
			{
				++total_wins;
				if (total_wins == 1)
					cout << "Part 1: " << board.get_points() * randnum << endl;
				else if (total_wins == boards.size())
					cout << "Part 2: " << board.get_points() * randnum << endl;
			}
		}
	}
}