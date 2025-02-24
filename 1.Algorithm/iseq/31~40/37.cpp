#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[9] = { 0 };
	int max = 0, min = 999;

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
		else if (arr[i] < min) min = arr[i];
	}

	int ch = max - min;

	cout << ch;
}