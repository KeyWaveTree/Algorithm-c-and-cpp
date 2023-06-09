#include <stdio.h>
#define NUM	300
int grid[NUM][NUM];

//큐 구조체 생성 
struct Q
{
	int x; 
	int y;
}
queue[NUM * NUM];

//값이 순환됨
//4 5
//1 1 1 1 0
//1 1 0 1 0
//1 1 0 0 0
//0 0 0 0 0
//1, 6이 계속 반복됨

//4 5
//1 1 0 0 0
//1 1 0 0 0
//0 0 1 0 0
//0 0 0 1 1
//3, 7이 계속 반복됨

//방향 순환 
//int arrowUD[] = { -1, 0, 1, 0 };//위, 아래
//int arrowRL[] = { 0, 1, 0, -1 };//오, 왼

void bfs(int row, int col, int m, int n)
{
	int x=0, y=0; 
	queue[0].x = row, queue[0].y = col;
	grid[row][col] = 0;
	int front = -1, rear = 0;
	//갈림길이 생겨났다면 queue에다가 저장
	while (1) {
		if (rear == front)break;
		front += 1;
		y = queue[front].y;
		x = queue[front].x;

		if (grid[y + 1][x] && y + 1< m) {
			rear += 1;
			queue[rear].x = x;
			queue[rear].y = y + 1;
			grid[y + 1][x] = 0;
		}
		if (grid[y - 1][x] && y-1 >= 0) {
			rear += 1;
			queue[rear].x = x;
			queue[rear].y = y - 1;
			grid[y - 1][x] = 0;
		}
		if (grid[y][x+1] && x+1<n) {
			rear += 1;
			queue[rear].x = x + 1;
			queue[rear].y = y;
			grid[y][x + 1] = 0;
		}
		if (grid[y][x-1] && x-1>=0) {
			rear += 1;
			queue[rear].x = x -1;
			queue[rear].y = y;
			grid[y][x -1] = 0;
		}
		/*
		if (grid[y + arrowUD[cnt % 4]][x + arrowRL[cnt % 4]] && !(y + arrowUD[cnt % 4]<0 || y + arrowUD[cnt % 4]> m || x + arrowRL[cnt % 4]<0 || x + arrowRL[cnt % 4]>n)
			&& check[y][x] == 0) {
			rear += 1;
			queue[rear].x = x + arrowRL[cnt % 4];
			queue[rear].y = y + arrowUD[cnt % 4];
			check[y + arrowUD[cnt % 4]][x + arrowRL[cnt % 4]] = 1;
		}*/
	}
}

// MODIFY THIS CODE
int get_mine(int m, int n) {
	//좌표 queue만들기
	int i, j;
	int result = 0;
	//일단 1찾기 
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (grid[i][j] == 1) // 좌표가 주어지면 탐색 
			{	
				bfs(i, j, &m, &n);
				result++;
			}
		}
	}
	//bfs를 이용해서 영역 
	
	
	return result;
}

int main() {
	/* DO NOT MODIFY */
	int i = 0, j = 0, m = 0, n = 0, result = 0;

	scanf("%d %d", &m, &n);
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
		}
	}

	result = get_mine(m, n);
	printf("%d\n", result);
	/* DO NOT MODIFY */
}