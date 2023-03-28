#include<stdio.h>

int main()
{
	float sw = 1;
	float bonza = 4;
	float j = 1;
	int n;
	float pi = 0;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{	
		pi += sw*(bonza / j);
		j += 2;
		sw *= -1;
	}
	printf("%f", pi);
}