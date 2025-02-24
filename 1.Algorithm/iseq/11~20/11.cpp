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
	if (a + b < 140) cout << a + b << "불합격" << endl;
	else cout << a + b << "합격" << endl;

	return 0;
}