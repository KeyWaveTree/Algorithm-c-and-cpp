#include<iostream>
#include<stdio.h>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, p=-1;
	int q;
	scanf("%d", &n);
	q = (n / 2) + 1;
	for (int i = 1; i <= n; i++)
	{
		if (i <= n / 2 + 1)
		{
			p += 2;
			q--;
		}
		else
		{
			p -= 2;
			q++;
		}

		for (int j = 1; j <= q; j++)
		{
			printf(" ");
		}

		for (int j = 1; j <=p; j++)
		{
			printf("*");
		}

		printf("\n");
	}
	return 0;
}