#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b;
	cin >> a >> b;
	if (a + b < 140) cout << a + b << "���հ�" << endl;
	else cout << a + b << "�հ�" << endl;

	return 0;
}