#include<stdio.h>

int cheak_prime(int i)
{
	int j = 0;
	for (j = 2; j < i * i; j++)
	{
		if (i % j == 0)break;
	}
	if (i == j) return 1;
	else return 0;
}

int main()
{

	for (int i = 1; i < 100; i++)
	{
		if (cheak_prime(i))
		{
			printf("%d ", i);
		}
	}
	return 0;
}