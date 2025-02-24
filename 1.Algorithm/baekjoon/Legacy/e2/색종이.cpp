#include<stdio.h>

int arr[100][100];
int main()
{
	freopen("output.txt", "w", stdout);

	int n;
	int x, y;
	int cnt = 0;
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &x, &y);

		for (int i = y - 1; i < (y + 10) - 1; i++)
		{
			for (int j = x - 1; j < (x + 10) - 1; j++)
			{
				if (!arr[i][j])
				{
					arr[i][j] = 1;
					cnt++;
				}
			}
		}
	}

	printf("%d", cnt);

	return 0;
}