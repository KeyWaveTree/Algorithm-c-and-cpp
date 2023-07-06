#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
	map<string, string> comp;
	string name;
	string state;
	int n;
	int i = 0;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> name;
		cin >> state;
		if (comp.find(name) != comp.end() && comp[name] !=state)
		{
			comp[name] = state;
		}
		else
		{
			comp.insert({ name,state });
		}	
	}

	for (auto i= comp.rbegin(); i!=comp.rend();i++)
	{
		if (i->second == "enter")
		{
			cout << i->first << '\n';
		}
	}

	return 0;
}