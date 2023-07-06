#include<iostream>
#define MAX_SIZE 51

using namespace std;

int map[MAX_SIZE][MAX_SIZE];

struct Q
{
	int cnt;
	int x;
	int y;
};

int bfs(int x, int y, int n, int m)
{
	struct Q queue[MAX_SIZE * MAX_SIZE*4] = { 0 };
	int front = -1, rear = 0;
	int cnt;
	queue[0].x = x, queue[0].y = y, queue[0].cnt=1;
	map[x][y] = queue[0].cnt;

	while (true)
	{
		if (front == rear) break;
		front++;
		cnt = queue[front].cnt;
		x = queue[front].x;
		y = queue[front].y;
		

		if (map[x - 1][y] == 0 && x - 1>=0)
		{
			rear++;
			map[x - 1][y] = cnt + 1;
			queue[rear].x = x - 1;
			queue[rear].y = y;
			queue[rear].cnt= cnt + 1;
		}
		if (map[x][y - 1] == 0 && y - 1 >= 0)
		{
			rear++;
			map[x][y - 1] = cnt + 1;
			queue[rear].x = x;
			queue[rear].y = y - 1;
			queue[rear].cnt= cnt + 1;
		}
		if (map[x + 1][y] == 0 && x + 1 < n)
		{
			rear++;
			map[x+1][y] = cnt + 1;
			queue[rear].x = x + 1;
			queue[rear].y = y;
			queue[rear].cnt = cnt + 1;
		}
		if (map[x][y + 1] == 0 && y + 1 < m)
		{
			rear++;
			map[x][y + 1] = cnt + 1;
			queue[rear].x = x;
			queue[rear].y = y+1;
			queue[rear].cnt = cnt + 1;
		}
	}
	return queue[front].cnt-1;
}

void cls_bfs(int x, int y, int n, int m)
{
	struct Q queue[MAX_SIZE * MAX_SIZE * 4] = { 0 };
	int front = -1, rear = 0;
	int cnt = 0;
	queue[0].x = x, queue[0].y = y;
	map[x][y] = queue[0].cnt;

	while (true)
	{
		if (front == rear) break;
		front++;
		x = queue[front].x;
		y = queue[front].y;


		if (map[x - 1][y] >= 1 && x - 1 >= 0)
		{
			rear++;
			map[x - 1][y] = cnt;
			queue[rear].x = x - 1;
			queue[rear].y = y;
		}
		if (map[x][y - 1] >= 1 && y - 1 >= 0)
		{
			rear++;
			map[x][y - 1] = cnt;
			queue[rear].x = x;
			queue[rear].y = y - 1;
		}
		if (map[x + 1][y] >= 1 && x + 1 < n)
		{
			rear++;
			map[x + 1][y] = cnt;
			queue[rear].x = x + 1;
			queue[rear].y = y;
		}
		if (map[x][y + 1] >= 1 && y + 1 < m)
		{
			rear++;
			map[x][y + 1] = cnt;
			queue[rear].x = x;
			queue[rear].y = y + 1;
		}
	}
}

int main()
{
	string v;
	int i, j;
	int n, m;

	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> v;
		for (j = 0; j < m; j++)
		{
			//map에다가 갈 수 있는지 없는지 표시
			if (v[j] == 'W')
			{
				map[i][j] = -1;
			}
			else if(v[j]=='L')
			{
				map[i][j] = 0;
			}
		}
	}

	int max = 0;
	int w=0;
	int flag = false;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (map[i][j] == 0 && flag==false)
			{
				w=bfs(i, j, n, m);
				flag = true;
			}
			if (w > max && flag) max = w;
			//printf("%4d", map[i][j]);
			if (flag)
			{
				cls_bfs(i, j, n, m);
				flag = false;
			}
		}
		//printf("\n");
	}

	printf("%d", max);
	return 0;
}