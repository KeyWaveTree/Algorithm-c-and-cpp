#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	string max;
	int max_len = 0;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		if (max_len < s.length()) max = s;
	}
	cout << max;
}