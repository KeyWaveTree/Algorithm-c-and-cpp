#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#define N 10

using namespace std;

int check[N][N], A[N][N], n, cnt;
int MAX;
int front, rear;

struct abc
{
	int h;
	int w;
}Q[N*N];

void input()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
		}
	}
}

void E(int h, int w)
{
	if (A[h + 1][w] == 1 && check[h + 1][w] == 0)
	{
		check[h + 1][w] = cnt;
		rear += 1;
		Q[rear].h = h + 1;
		Q[rear].w = w;
	}
	if (A[h - 1][w] == 1 && check[h - 1][w] == 0) {
			check[h - 1][w] = cnt;
			rear += 1;
			Q[rear].h = h - 1;
			Q[rear].w = w;
	}
		if (A[h][w + 1] == 1 && check[h][w + 1] == 0) {
			check[h][w + 1] = cnt;
			rear += 1;
			Q[rear].h = h;
			Q[rear].w = w + 1;
		}
		if (A[h][w - 1] == 1 && check[h][w - 1] == 0) {
			check[h][w - 1] = cnt;
			rear += 1;
			Q[rear].h = h;
			Q[rear].w = w - 1;
		}
}

void run()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (A[i][j] == 1 && check[i][j]==0)
			{
				rear = front = 0;
				cnt++;
				check[i][j] = cnt;
				
				rear++;
				Q[rear].h = i;
				Q[rear].w = j;

				while (1)
				{
					if (front == rear)
					{
						if (MAX < rear) MAX = rear;
						break;
					}
					front++;
					E(Q[front].h, Q[front].w);
				}
			}
		}
	}
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout<< A[i][j];
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();


	print();
}