#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++)
		{
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}