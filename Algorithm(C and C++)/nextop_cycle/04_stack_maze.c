#define _CRT_SECURE_NO_WANINGS
#include<stdio.h>
#define SIZE 10

int n;
int arr[SIZE][SIZE];

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

void q(int h, int w, int l)
{
	if (h > n || w > n || h<=0 || w<=0) return;
	if (arr[h][w] != 0) return;

	arr[h][w] = l;

	if (h == n && w == n)
	{
		print();
		arr[h][w] = 0;
		return;
	}

	q(h + 1, w, l + 1);
	q(h, w + 1, l + 1);
	q(h - 1, w, l + 1);
	q(h, w - 1, l + 1);

	arr[h][w] = 0;
}

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	q(1, 1, 1);
}