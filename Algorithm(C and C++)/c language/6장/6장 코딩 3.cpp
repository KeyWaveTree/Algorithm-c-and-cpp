#include<stdio.h>

int main()
{
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			if (i < j)
			{
				printf("*");
			}
			else printf("%d", j);
			
		}
		printf("\n");
	}
}