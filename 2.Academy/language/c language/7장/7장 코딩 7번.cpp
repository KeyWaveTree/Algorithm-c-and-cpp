#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);

	int one[100][100] = { 0 };
	int two[100][100] = { 0 };
	int value[100][100] = { 0 };

	int r;
	int c;

	printf("��");
	scanf("%d", &r);
	printf("��");
	scanf("%d", &c);

	printf("1 ���");
	for (int rr = 0; rr < r; rr++)
	{
		for (int cc = 0; cc < c; cc++)
		{
			scanf("%d", &one[rr][cc]);
		}
	}

	printf("2 ���");
	for (int rr = 0; rr < r; rr++)
	{
		for (int cc = 0; cc < c; cc++)
		{
			scanf("%d", &two[rr][cc]);
		}
	}

	for (int rr = 0; rr < r; rr++)
	{
		for (int cc = 0; cc < r; cc++)
		{
			for (int ii = 0; ii < r; ii++)
			{
				 value[rr][cc]+= one[rr][ii] * two[ii][cc];
			}
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < r; j++)
		{
			printf("%d ", value[i][j]);
		}
		printf("\n");
	}
}