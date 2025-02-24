#include<stdio.h>

int map[10][10];
int queue[4][10];
int check[10];

int n;
int cnt = 0;

void input()
{
	int i, j;
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
	int h, w, l;
	queue[rear][1] = 1;//h
	queue[rear][2] = 1;//w
	queue[rear][3] = 1;//l
	
	while (1)
	{
		if (front == rear) break;
		front += 1;
		h = queue[front][1];
		w = queue[front][2];
		l = queue[front][3];

		if (h + 1 <= n && map[h + 1][w])
		{
			rear++;
			queue[rear][1] = h + 1;
			queue[rear][2] = w;
			queue[rear][3] = l+1;
			map[h + 1][w] = l + 1;
		}

		if (h - 1 >0 && map[h -1][w])
		{
			rear++;
			queue[rear][1] = h - 1;
			queue[rear][2] = w;
			queue[rear][3] = l + 1;
			map[h - 1][w] = l + 1;
		}

		if (w + 1 <= n && map[h][w+1])
		{
			rear++;
			queue[rear][1] = h;
			queue[rear][2] = w+1;
			queue[rear][3] = l + 1;
			map[h][w+1] = l + 1;
		}

		if (w-1 > 0 && map[h][w-1])
		{
			rear++;
			queue[rear][1] = h;
			queue[rear][2] = w - 1;
			queue[rear][3] = l + 1;
			map[h][w - 1] = l + 1;
		}
	}
}

void print()
{
	int i, j;
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= n; j++)
		{
			printf("%3d", map[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	run();
	print();

}