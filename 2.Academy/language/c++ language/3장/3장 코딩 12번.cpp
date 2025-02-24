#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	int a[26] = { 0};
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '\0') continue;
		a[(int)s[i] - 'a']++;
	}

	for (char al = 'a'; al <= 'z'; al++)
	{
		cout << al << ":" << a[(int)al - 'a']<<'\n';
	}
}