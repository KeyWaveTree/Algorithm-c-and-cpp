#include<iostream>
#include<vector>

using namespace std;

int main()
{
	vector<int>v;
	int a;
	int sum = 0;

	do
	{

		cin >> a;
		v.push_back(a);

	} while (a != -1);
	v.pop_back();

	for (auto i = v.begin(); i < v.end(); i++)
	{
		sum += *i;
	}

	cout << sum / v.size();

	return 0;
}