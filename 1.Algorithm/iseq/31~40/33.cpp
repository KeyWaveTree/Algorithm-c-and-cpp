#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
 
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	if ((n % 400 == 0 || n % 100 != 0) && n % 4 == 0)
	{
		cout << "À±³â" << endl;
	}
	else 
	{
		cout << "Æò³â" << endl;
	}
}
