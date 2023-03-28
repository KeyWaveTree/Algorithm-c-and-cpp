#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[10] = { 0 };
	int max = 0;
	int min = 99;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}	
	cout << max << endl;
	cout << min << endl;
}