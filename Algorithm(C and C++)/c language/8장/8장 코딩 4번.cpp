#include<stdio.h>

void get_divisor(int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%d ", i);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	get_divisor(n);
}