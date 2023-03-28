#include<stdio.h>
#include<math.h>

int power(int n, int m)
{
	int p = 1;
	int i;
	for (i = 0; i < m; i++)
	{
		p *= n;
	}
	return p;
}

int main()
{
	for (int i = 0; i <= 10; i++)
	{
		printf("%d ", power(3, i));
	}
}