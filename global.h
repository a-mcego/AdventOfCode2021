#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

using uint = unsigned int;

template<typename T>
T FromString(string s)
{
	stringstream ss(s);
	T ret;
	ss >> ret;
	return ret;
}

template<typename T>
vector<T> FromString(vector<string> sv)
{
	vector<T> ret;
	for (const string& s : sv)
	{
		stringstream ss(s);
		T tmp;
		ss >> tmp;
		ret.push_back(tmp);
	}
	return ret;
}

template<typename T>
string ToString(T t)
{
	stringstream ss;
	ss << t;
	return ss.str();
}

static vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}


template<typename T, int N>
vector<T> readthings(ifstream& file)
{
	vector<T> ret;
	for (int i = 0; i < N; ++i)
	{
		T t;
		file >> t;
		if (file.eof())
			return vector<T>();
		ret.push_back(t);
	}
	return ret;
}

static vector<string> GetLines(string filename)
{
	ifstream file(filename);
	vector<string> ret;
	while (true)
	{
		string str;
		std::getline(file, str);
		if (file.eof())
			break;
		ret.push_back(str);
	}
	return ret;
}

void day01();
void day02();
void day03();
void day04();

static void(*funcs[])() =
{
	nullptr,
	day01,
	day02,
	day03,
	day04
};
