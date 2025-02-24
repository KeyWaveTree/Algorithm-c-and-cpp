#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
 
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	float arr[10] = { 0 };
	float min = 999, nag = 1;
	for (int i = 0; i <10; i++)
	{
		cin >> arr[i];

		if (arr[i]<0 ) //음수일때
		{
			if (-arr[i] < min)
			{
				min = arr[i];
			}
		}
		else if (arr[i] > 0 )
		{
			if (!min > 0 && arr[i] < -min)
			{
				min = arr[i];
			}
			else if (arr[i] < min && min>0)
			{
				min = arr[i];
			}
		}
	}
	cout << min << endl;
}