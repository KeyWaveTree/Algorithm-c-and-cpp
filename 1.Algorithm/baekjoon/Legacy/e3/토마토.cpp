#include<iostream>

using namespace std;

int box[102][102][102];
int n, m, h;

int front = -1, rear = 0;

struct Q
{
	int x; //이 데이터가 있는 좌표 위치 x
	int y; // 이 데이터가 있는 좌표 위치 y
	int z;
	int cnt = 1;
}q[100 * 100 * 100];



void bfs(int x, int y, int z, int cnt)
{
	if (box[z][y][x - 1] == 0 && x - 1 >= 0)
	{
		//좌로 움직일때 가로길이를 벗어나지 않고 값이 1이 아니거나 -1이 아닌경우에

		box[z][y][x - 1] = cnt + 1;
		q[rear].x = x - 1;
		q[rear].y = y;
		q[rear].z = z;
		q[rear].cnt = cnt + 1;
		rear++;
	}

	//우 좌
	if (box[z][y][x + 1] == 0 && x + 1 < n)
	{
		//우로 움직일때 가로길이를 벗어나지 않고 값이 1이 아니거나 -1이 아닌경우에 
		//처리할 경우 증가 
		box[z][y][x + 1] = cnt + 1;
		q[rear].x = x + 1;
		q[rear].y = y;
		q[rear].z = z;
		q[rear].cnt = cnt + 1; 
		rear++;
	}


	//위 아래
	if (box[z][y - 1][x] == 0 && y - 1 >= 0)
	{
		//위로 움직일때 세로길이를 벗어나지 않고 값이 1이아니거나 -1이 아닌경우

		box[z][y - 1][x] = cnt + 1;
		q[rear].x = x;
		q[rear].y = y - 1;
		q[rear].z = z;
		q[rear].cnt = cnt + 1;		
		rear++;
	}

	if (box[z][y + 1][x] == 0 && y + 1 < m)
	{
		//아레로 움직일때 세로길이를 벗어나지 않고 값이 1이아니거나 -1이 아닌경우

		box[z][y + 1][x] = cnt + 1;
		q[rear].x = x;
		q[rear].y = y + 1;
		q[rear].z = z;
		q[rear].cnt = cnt + 1;		
		rear++;
	}

	//앞 뒤
	if (box[z - 1][y][x] == 0 && z - 1 >= 0)
	{

		box[z - 1][y][x] = cnt + 1;
		q[rear].x = x;
		q[rear].y = y;
		q[rear].z = z - 1;
		q[rear].cnt = cnt + 1;		
		rear++;
	}

	if (box[z + 1][y][x] == 0 && z + 1 < h)
	{

		box[z + 1][y][x] = cnt + 1;
		q[rear].x = x;
		q[rear].y = y;
		q[rear].z = z + 1;
		q[rear].cnt = cnt + 1;		
		rear++;
	}

	//처리 끝난 다음 반복횟수 증가
}


int main()
{
	int i, j, k;
	int cnt = 0;
	bool q_flag = false;
	cin >> n >> m >> h;

	for (k = 0; k < h; k++)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cin >> box[k][i][j];
				//현재 익은 토마토 위치를 저장
				//위치를 뽑아 bfs로 넘김
				//반복을 덜하기 위해서 
				if (box[k][i][j] == 1)
				{
					q[rear].x = j;
					q[rear].y = i;
					q[rear].z = k;
					rear++;
					q_flag = true;
				}
				else {
					continue;
				}
			}
		}
	}
	if (q_flag == false)
	{
		front = rear;
	}

	int max = 0;
	bool flag = false;
	int x, y, z;
	while (1)
	{
		if (front == rear) break;
		//반복이 되면서 처리 해줘야 함
		front++;
		x = q[front].x;
		y = q[front].y;
		z = q[front].z;
		cnt = q[front].cnt;
		bfs(x, y, z, cnt);
	}

	//내가 구한 수 중에서 가장 큰값을 찾아야 함
	//내가 bfs를 다돌았을때 아직 토마토가 다 안익은 경우가 있을 수 있다. 따라서 체크를 해야 한다. 
	for (k = 0; k < h; k++)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (box[k][i][j] == 0)
				{
					flag = true;
				}
				else if (max < box[k][i][j])
				{
					max = box[k][i][j];
				}
		
			}
		}
	}
	if (flag)
	{
		printf("%d\n", -1);
	}
	else
	{
		printf("%d\n", max - 1);
	}

	return 0;
}