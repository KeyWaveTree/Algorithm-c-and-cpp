#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 10

int i, j, L = 0, flag = 1;
int front, rear;

int A[N][N], n;

struct Q 
{
	int w;
	int h;
	int v;

}Q[N*N];

void E(int h, int w, int L) {
	if (A[h + 1][w] == 0 && h + 1 <= n)
	{
		A[h + 1][w] = L + 1;
		rear++;
		Q[rear].h = h + 1;
		Q[rear].w = w;
		Q[rear].v = L + 1;
	}
	if (A[h - 1][w] == 0 && h - 1 > 0)
	{
		A[h - 1][w] = L + 1;
		rear++;
		Q[rear].h = h - 1;
		Q[rear].w = w;
		Q[rear].v = L + 1;

	}
	if (A[h][w + 1] == 0 && w + 1 <= n)
	{
		A[h][w + 1] = L + 1;
		rear++;
		Q[rear].h = h;
		Q[rear].w = w + 1;
		Q[rear].v = L + 1;
	}
	if (A[h][w - 1] == 0 && w - 1 > 0)
	{
		A[h][w - 1] = L + 1;
		rear++;
		Q[rear].h = h;
		Q[rear].w = w - 1;
		Q[rear].v = L + 1;
	}

}

void input() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
}


void print() {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	int i, j, L = 0;
	input();
	A[1][1] = 1; //1,1 출발
	//rear 실제 값 
	rear++;
	Q[rear].w = Q[rear].h = Q[rear].v = 1;
	while (1) {
		if (front == rear) break;
		front++;
		i = Q[front].w;
		j = Q[front].h;
		L = Q[front].v;
		E(i, j, L);
	}
	print();



	return 0;
}