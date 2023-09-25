#include<stdio.h>

int n = 20;
int a[30][30];

int main()
{
	int i, j, k, cnt=1;

	a[7][7] = 1;
	for (k = 0; k < 5; k++)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (a[i][j] == cnt)
				{
					if (i + 1 <= n && a[i + 1][j] == 0)
					{
						a[i + 1][j] = cnt + 1;
					}
					if (i - 1 > n && a[i - 1][j] == 0)
					{
						a[i - 1][j] = cnt + 1;

					}
					if (j + 1 <= n && a[i][j + 1] == 0)
					{
						a[i][j + 1] = cnt + 1;
					}
					if (j - 1 <= n && a[i][j - 1] == 0)
					{
						a[i][j - 1] = cnt + 1;
					}
				}
			}
		}
		cnt++;
	}


	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}