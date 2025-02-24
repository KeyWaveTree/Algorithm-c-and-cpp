#define _CRT_SECURE_NO_WARNIGS
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	int j;
	cin >> n >> m;

	for (int i = n; i <= m; i++)
	{
		for (j = 2; j < i; j++)
		{
			if (i % j == 0) break;
		}
		if (i == j) cout << j <<" ";
	}
}