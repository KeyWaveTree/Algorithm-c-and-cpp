#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char n;
	for (int i = 0; i < 3; i++)
	{
		cin >> n;
		if (i == 2) 
		{
			printf("%c %d", n, n);
		}
	}

	/*char arr[10] = { '\0'};
	for (int i = 1; i < 10; i++)
	{
		cin >> arr[i];
		if(i==3)
		{ 
			printf("%c %d", arr[i], arr[i]);
			break;
		}
	}*/

	return 0;
}