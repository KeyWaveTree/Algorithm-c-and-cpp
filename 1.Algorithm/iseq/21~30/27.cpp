#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	cin >> n >> m;
	for (n; n <= m; n++)
	{
		if (n % 10 == 3 || n % 10 == 6 || n % 10 == 9)
		{
			cout << n << endl;
		}
	}
}