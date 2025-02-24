#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);

	int n;
	int sum = 0;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		if (i % 3 == 0)
		{
			sum += i;
		}
	}
	printf("%d", sum);
}