#include<stdio.h>

int arr[1024][1024];
int main()
{
	int n;
	int m;
	int x1, y1;
	int x2, y2;
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	for (int k = 0; k < m; k++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	}
	return 0;
}