#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <random>
#include <time.h>

using namespace std;

class Bacteria
{
public:
	Bacteria(const string& first_name, const string& last_name)
		: first_name{ add(first_name) },
		last_name{ add(last_name) }
	{
	}

	const string& get_first_name() const
	{
		return names[first_name];
	}

	const string& get_last_name() const
	{
		return names[last_name];
	}

	friend ostream& operator<< (ostream& os, const Bacteria& obj)
	{
		return os
			<< "first name: " << obj.first_name << " " << obj.get_first_name()
			<< " last name: " << obj.last_name << " " << obj.get_last_name();
	}

protected:
	static vector<string> names;
	static int seed;

	static int add(const string& s)
	{
		int pos = 0;
		for (pos = 0; pos < names.size(); pos++)
		{
			if (names[pos] == s)
				return pos;
		}
		names.push_back(s);
		return pos;
	}
	int first_name, last_name;
};

int Bacteria::seed = 0;
vector<string> Bacteria::names{};

class BacteriaFactory
{
public:
	Bacteria create_new(const Bacteria& parent)
	{
		char letter = rand() % 25 + 'a';
		Bacteria new_bac{ parent.get_first_name() + letter, parent.get_last_name() + letter };
		return new_bac;
	}
};