#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>

using namespace std;

bool compare(const string &i,const string &j)
{
	if (i.length() == j.length()) return i < j;
	return i.length() < j.length();
}

int main()
{
	int n;
	string text;
	set<string> word;
	vector<string> w;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> text;
		word.insert(text);
	}

	for (auto& i : word)
	{
		w.push_back(i);
	}

	sort(w.begin(), w.end(), compare);

	for (auto& i : w)
	{
		cout << i << '\n';
	}

	return 0;
}