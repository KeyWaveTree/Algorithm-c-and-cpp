#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
	{
		for (int j = n; j > 0; j--)
		{
			printf("%d\t", n * j - i);
		}
		printf("\n");
	}
}