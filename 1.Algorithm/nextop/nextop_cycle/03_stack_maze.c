#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int m[100][100];
int n;

void print()
{
	int i, j;

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void maze(int h, int w)
{
	if (h > n || w > n) return;

	m[h][w] = 1;

	if (h == n && w == n)
	{
		print();
		return;
	}
	maze(h + 1, w);
	maze(h, w + 1);
	
	m[h][w] = 0;
}

int main()
{
	scanf("%d", &n);
	maze(1, 1);

	return 0;
}