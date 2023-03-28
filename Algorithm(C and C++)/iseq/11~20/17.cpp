#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int arr[10] = { 0 };
	int i ,cnt = 0;
	int sum = 0;
	while (1)
	{
		cin >> i;
		if (i == 0) break;
		arr[cnt++]=i;
		if (arr[cnt - 1] < 0) sum += (-1 * arr[cnt - 1]);
		else sum += arr[cnt - 1];
	}
	cout << sum;
}