#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char str[20] = { '\0' };
	gets_s(str, sizeof(str));

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == 'A') str[i] = '*';
	}

	for (int i = 0; i < strlen(str); i++)
	{
		cout << str[i];
	}
}