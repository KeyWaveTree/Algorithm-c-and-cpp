#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int arr[10] = { 0 };
	int cnt = 0;
	float avr = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		if (arr[i] >= 60)
		{
			cnt++;
			avr += arr[i];
		}
	}
	cout << cnt << endl;
	printf("%.2f", avr / cnt);

	return 0;
}