#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	char arr[10] = { 'Y', 'B','K','E','A', 'R', 'N', 'D', 'O', 'G' };
	char input[100] = { '\0' };

	cin >> input;

	for (int i = 0; i < strlen(input); i++)
	{
		cout << arr[(int)input[i] - '0'];
	}

	return 0;
}