#include<stdio.h>

int main()
{
	int v;
	int max = 0;
	int min= 1000001;
	int real;

	scanf("%d", &v);
	for (int i = 0; i < v; i++)
	{
		scanf("%d", &real);
		if (min > real)
		{
			min = real;
		}
		if (max < real)
		{
			max = real;
		}
	}

	printf("%d", min * max);

	return 0;
}