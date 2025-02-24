#include<stdio.h>

int map[10][10];
int queue[4][10];
int check[10];
int i, j;
int n;
int cnt = 0;

void input()
{
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
}

void run()
{
	int front = 0, rear = 1;
	int start, level;
	queue[rear][1] = 1;
	queue[rear][2] = 1;
	check[1] = 1;
	while (1)
	{
		if (front == rear) break;
		front+=1;
		start = queue[front][1];
		level = queue[front][2];

		for (int i = 1; i <= n; i++)
		{
			if (map[start][i] == 1 && check[i] == 0)
			{
				rear += 1;
				queue[rear][1] = i;
				queue[rear][2] = level + 1;
				check[i] = 1;
			}
		}
	}
}

void print()
{
	for (i = 1; i <= 6; i++)
	{
		printf("%d ", queue[i][1]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	run();
	print();

}