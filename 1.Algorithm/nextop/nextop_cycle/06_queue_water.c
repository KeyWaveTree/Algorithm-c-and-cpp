#include<stdio.h>

int n = 20;
int a[30][30];
int q[400][3];

int front, rear = 1;

int main()
{
	int i = q[rear][1] = 7;
	int j = q[rear][2] = 7;
	int cnt = q[rear][3] = 1;
	a[i][j] = cnt;

	while (1)
	{
		if (front == rear) break;
		front++;
		i = q[front][1];
		j = q[front][2];
		cnt = q[front][3];

		if (i + 1 <= n && a[i + 1][j]==0)
		{
			rear++;
			q[rear][1] = i + 1;
			q[rear][2] = j;
			q[rear][3] = cnt + 1;
			a[i + 1][j] = cnt + 1;
		}
		
		if (i - 1 > 0 && a[i - 1][j]==0)
		{
			rear++;
			q[rear][1] = i - 1;
			q[rear][2] = j;
			q[rear][3] = cnt + 1;
			a[i - 1][j] = cnt + 1;
		}

		if (j + 1 <= n && a[i][j + 1]==0)
		{
			rear++;
			q[rear][1] = i;
			q[rear][2] = j+1;
			q[rear][3] = cnt + 1;
			a[i][j+1] = cnt + 1;
		}

		if (j - 1 > 0 && a[i][j - 1] == 0)
		{
			rear++;
			q[rear][1] = i;
			q[rear][2] = j-1;
			q[rear][3] = cnt + 1;
			a[i][j-1] = cnt + 1;
		}
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