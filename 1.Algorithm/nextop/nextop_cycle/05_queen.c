#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define SIZE 10

int n;
int arr[SIZE+1][SIZE+1];

void print()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void q(int h, int w)
{
	int i;
	//위아래
	for (i = 1; i < h; i++)
	{
		if (arr[i][w] == 1) return;
	}

	//왼쪽 대각선
	for (i = 1;; i++)
	{
		if (h - i < 1 || w - i < 1) break;
		if (arr[h - i][w - i] == 1) return;
	}
	
	//오른쪽 대각선
	for (i = 1;; i++)
	{
		if (h - i < 1 || w + i>n) break;
		if (arr[h - i][w + i] == 1) return;
	}
	
	//퀸표시
	arr[h][w] = 1;
	
	if (h == n)
	{
		print();
		arr[h][w] = 0;
	}

	for (i = 1; i <= n; i++)
	{
		q(h + 1, i);
	}
	arr[h][w] = 0;
}

int main()
{
	scanf("%d", &n);
	q(0, 0);
}