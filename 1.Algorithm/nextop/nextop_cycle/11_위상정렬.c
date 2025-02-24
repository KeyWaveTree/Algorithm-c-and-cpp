#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int map[100][100];
int queue[100][4];
int save_node[400][4];

int n,k;
int cnt = 0;

void input()
{
	int i, j;
	int s, e, v;
	int cnt;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= k; i++)
	{
		scanf("%d %d %d", &s, &e, &v);
		map[s][e] = v;
	}

	for (i = 1; i <= n; i++)
	{
		cnt = 0;
		for (j = 1; j <= n; j++)
		{
			if (map[j][i]!=0) cnt++;
		}
		save_node[i][1] = i; //node
		save_node[i][2] = cnt; //edge
		save_node[i][3] = 987654321; //cost

	}
}

void run()
{
	int i;
	int front = 0, rear = 1;
	int node, cost;
	queue[rear][1] = save_node[rear][1];
	queue[rear][3] = 0;

	while (1)
	{
		if (front == rear) break;
		front += 1;
		node = queue[front][1];
		cost = queue[front][3];

		for (i = 1; i <= n; i++) //end
		{
			if (map[node][i] != 0 && save_node[i][3] > map[node][i] + cost)
			{
				save_node[i][3] = map[node][i] + cost;
				save_node[i][2]--;
				if (save_node[i][2] == 0)
				{
					rear++;
					queue[rear][1] = i;
					queue[rear][3] = save_node[i][3];
				}
			}
		}
	}
}

void print()
{
	int i, j;
	for (i = 1; i <= 6; i++)
	{
		printf("%3d %3d", queue[i][1], queue[i][3]);
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