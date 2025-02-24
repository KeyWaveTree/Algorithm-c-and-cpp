#include<stdio.h>
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//c
	int n;
	int cnt;

	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j < n; j++) printf(" ");

		cnt = 0;
		for (int j = 1; j <= i * 2 - 1;j++)
		{
			if (i >= j) cnt++;
			else cnt--;
			printf("%d", cnt);
		}
		printf("\n");
	}

	return 0;
}