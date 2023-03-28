#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n = -1;

	while (1)
	{
		cin >> n;
		switch(n)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			cout << n << '-' << 31 << endl;
			continue;
		case 2:
			cout << n << '-' << 28 << endl;
			continue;
		case 4:
		case 6:
		case 9:
		case 11:
			cout << n << '-' << 30 << endl;
			continue;
		case 0:
			break;
		default:
			cout << n << '-' << 99 << endl;
			continue;
		}
	}

}