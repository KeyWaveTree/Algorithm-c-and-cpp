#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//1 c
	char arr[100] = {'\0'};
	int k=0;
	
	gets_s(arr, sizeof(arr));

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == '@') 
		{
			k = i;
			break;
		}
	}
	
	for (int i = k + 1; i < strlen(arr); i++)
	{
		printf("%c", arr[i]);
	}
	printf("@");
	for (int i = 0; i < k; i++)
	{
		printf("%c", arr[i]);
	}
	return 0;
}