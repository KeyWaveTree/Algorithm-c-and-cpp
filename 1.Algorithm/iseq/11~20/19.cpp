#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
int getMyInt(char arr[])
{
	int i = 0, num = 0;
	while (arr[i] != 0)
	{
		num = num * 10 + arr[i] - '0';
		i++;
	}
	return num;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int sum = 0;
	char ci[10] = { '\0' };
	char val[4][4] = { '\0' };

	for (int i = 0;i < 3; i++)
	{
		gets_s(val[i], sizeof(val[i]));
		if (i == 2)
		{
			sum += getMyInt(ci);
			sum += getMyInt(val[i]);
		}
		else strcat(ci, val[i]);
	}
	cout << sum;
}