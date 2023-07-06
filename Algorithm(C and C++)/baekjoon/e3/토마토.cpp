#include<iostream>

using namespace std;

int box[102][102][102];
int n, m, h;

int front = -1, rear = 0;

struct Q
{
	int x; //�� �����Ͱ� �ִ� ��ǥ ��ġ x
	int y; // �� �����Ͱ� �ִ� ��ǥ ��ġ y
	int z;
	int cnt = 1;
}q[100 * 100 * 100];



void bfs(int x, int y, int z, int cnt)
{
	if (box[z][y][x - 1] == 0 && x - 1 >= 0)
	{
		//�·� �����϶� ���α��̸� ����� �ʰ� ���� 1�� �ƴϰų� -1�� �ƴѰ�쿡

		box[z][y][x - 1] = cnt + 1;
		q[rear].x = x - 1;
		q[rear].y = y;
		q[rear].z = z;
		q[rear].cnt = cnt + 1;
		rear++;
	}

	//�� ��
	if (box[z][y][x + 1] == 0 && x + 1 < n)
	{
		//��� �����϶� ���α��̸� ����� �ʰ� ���� 1�� �ƴϰų� -1�� �ƴѰ�쿡 
		//ó���� ��� ���� 
		box[z][y][x + 1] = cnt + 1;
		q[rear].x = x + 1;
		q[rear].y = y;
		q[rear].z = z;
		q[rear].cnt = cnt + 1; 
		rear++;
	}


	//�� �Ʒ�
	if (box[z][y - 1][x] == 0 && y - 1 >= 0)
	{
		//���� �����϶� ���α��̸� ����� �ʰ� ���� 1�̾ƴϰų� -1�� �ƴѰ��

		box[z][y - 1][x] = cnt + 1;
		q[rear].x = x;
		q[rear].y = y - 1;
		q[rear].z = z;
		q[rear].cnt = cnt + 1;		
		rear++;
	}

	if (box[z][y + 1][x] == 0 && y + 1 < m)
	{
		//�Ʒ��� �����϶� ���α��̸� ����� �ʰ� ���� 1�̾ƴϰų� -1�� �ƴѰ��

		box[z][y + 1][x] = cnt + 1;
		q[rear].x = x;
		q[rear].y = y + 1;
		q[rear].z = z;
		q[rear].cnt = cnt + 1;		
		rear++;
	}

	//�� ��
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

	//ó�� ���� ���� �ݺ�Ƚ�� ����
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
				//���� ���� �丶�� ��ġ�� ����
				//��ġ�� �̾� bfs�� �ѱ�
				//�ݺ��� ���ϱ� ���ؼ� 
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
		//�ݺ��� �Ǹ鼭 ó�� ����� ��
		front++;
		x = q[front].x;
		y = q[front].y;
		z = q[front].z;
		cnt = q[front].cnt;
		bfs(x, y, z, cnt);
	}

	//���� ���� �� �߿��� ���� ū���� ã�ƾ� ��
	//���� bfs�� �ٵ������� ���� �丶�䰡 �� ������ ��찡 ���� �� �ִ�. ���� üũ�� �ؾ� �Ѵ�. 
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