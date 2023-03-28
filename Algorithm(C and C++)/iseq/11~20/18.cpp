#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char arr[5][10] = {'\0'};
	int cnt = 0;
	for (int k = 0; k < 5; k++)
	{
		gets_s(arr[k], sizeof(arr[k]));
		
		for (int i = 0;; i++)
		{
			if (arr[k][i] != '\0')
			{
				cnt++;
			}
			else 
			{
				break;
			}
		}
	}
	cout << cnt;
	
}