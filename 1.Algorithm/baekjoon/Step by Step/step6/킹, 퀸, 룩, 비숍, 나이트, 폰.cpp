#include<stdio.h>
int main()
{
	int c[6] = {1,1,2,2,2,8};
	int check[6] = {0};

	for (int i = 0; i < 6; i++)
	{
		scanf("%d", &check[i]);
		printf("%d ", c[i] - check[i]);
	}
}