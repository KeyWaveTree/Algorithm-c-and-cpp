#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

using namespace std;

int gdc(int n, int m)
{
	if (m == 0) return n;
	else gdc(m, n % m);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	cin >> n >> m;
	cout << gdc(n, m);
	
}