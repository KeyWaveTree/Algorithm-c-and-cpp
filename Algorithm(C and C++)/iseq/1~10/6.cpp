#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int wr, hr;
	
	cin >> wr;

	hr = (wr * 4) / 3;

	cout << hr << endl;
}