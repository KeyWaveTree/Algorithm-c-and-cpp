#include<stdio.h>

int main()
{
	int n;
	int j;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		for (j = 2; j < i * i; j++)
		{
			if (i % j == 0) break;
		}
		if (i == j) printf("%d ", j);
	}
	return 0;
}