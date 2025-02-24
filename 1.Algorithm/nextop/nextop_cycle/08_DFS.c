#include<stdio.h>

int map[10][10];
int output[10];
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

void run(int node)
{
	int i;
	output[cnt] = node;
	check[node] = 1;
	for (i = 1; i <= n; i++)
	{
		if (map[node][i] == 1 && check[i] == 0)
		{
			cnt++;
			run(i);
		}
	}
}

void print()
{
	int i;
	for (i = 0; i < 6; i++)
	{
		printf("%d ", output[i]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input();
	run(1);
	print();
	
}