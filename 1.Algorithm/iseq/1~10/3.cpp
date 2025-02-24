#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;
	int mok, na;

	cin >> a >> b;
	mok = a / b;
	na = a % b;

	cout << mok << endl; 
	cout << na << endl;
}