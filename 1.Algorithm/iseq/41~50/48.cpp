#include<stdio.h>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//c 
	char arr[100] = { '\0' };
	int cnt, j;

	gets_s(arr, sizeof(arr));
	for (int i = 0; i < strlen(arr); i++)
	{
		cnt = 0;
		for (j = i; j < strlen(arr); j++)
		{
			if (arr[i] == arr[j]) cnt++;
			else break;
		}

		if (cnt >= 5)
		{
			printf("%c(%d)", arr[i], cnt);
			i += (cnt-1);
		}
		else printf("%c", arr[i]);
	}
	
	return 0;
}