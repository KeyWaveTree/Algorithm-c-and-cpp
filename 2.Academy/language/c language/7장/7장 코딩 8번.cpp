#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);

	int one[100][100] = { 0 };

	int r;
	int c;

	printf("행");
	scanf("%d", &r);
	printf("열");
	scanf("%d", &c);

	printf("1 행렬");
	for (int rr = 0; rr < r; rr++)
	{
		for (int cc = 0; cc < c; cc++)
		{
			scanf("%d", &one[rr][cc]);
		}
	}

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			printf("%d ", one[i][j]);
		}
		printf("\n");
	}
}