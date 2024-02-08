#include<iostream>

using namespace std;

int main()
{
	int n;
	int i, j;
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("*");
		}

		printf("\n");
	}
	return 0;
}