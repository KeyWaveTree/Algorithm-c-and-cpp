#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	cin >> n;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << j+1;
		}
		cout << endl;
	}
}