#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 0) sum += i;
		else continue;
	}
	cout << sum;
}