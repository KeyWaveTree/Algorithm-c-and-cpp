#include <iostream>

using namespace std;

const int INF = 1e9;

int matrix[101][101];
int check[101];

int node;
int edge;

void dfs_max(int start, int weight)
{
	int dist;
	check[start] = 1;

	for (dist = 1; dist <= node; dist++)
	{ 
		if (matrix[start][dist] >= weight && matrix[start][dist] != INF && check[dist] == 0)
		{
			dfs_max(dist, weight);
		}
	}

}

void dfs_min(int start, int weight)
{
	int dist;
	check[start] = 1;

	for (dist = 1; dist <= node; dist++)
	{
		if (matrix[start][dist] <= weight && matrix[start][dist] != INF && check[dist] == 0)
		{
			dfs_min(dist, weight);
		}
	}

}

int main()
{
	int i, j;
	int start = 0, end = 0;
	scanf("%d", &node);
	scanf("%d", &edge);

	for (i = 1; i <= node; i++)
	{
		for (j = 1; j <= node; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			matrix[i][j] = INF;
		}
	}

	for (i = 0; i < edge; i++)
	{
		scanf("%d %d", &start, &end);

		matrix[start][end] = 1;
		matrix[end][start] = -1;
	}
	
	int total_check[101] {};
	for (i = 1; i <= node; i++)
	{
		dfs_max(i,  1);
		for (int j = 1; j <= node; j++) {
			total_check[j] += check[j];
			check[j] = 0;
		}
		dfs_min(i, -1);
		for (int j = 1; j <= node; j++) {
			total_check[j] += check[j];
			check[j] = 0;
		}

		int cnt = 0;
		for (int j = 1; j <= node; j++) {
			if (total_check[j] == 0) cnt++;
			total_check[j] = 0;
		}

		printf("%d\n", cnt);
	}

	return 0;
}


/*
1 2
2 3
3 1

[1][2] = 1
[2][1] = -1

[2][3] = 1
[3][2] = -1

[3][1] = 1
[1][3] = 3

�� ��� �� �� ���� �ۼ��� �ڵ带 ���� 
#include<iostream>
#include<cstring>
#define INF 987654321

using namespace std;
//1�� Ǯ��
//dfs�� �� �� ǥ��

//2�� Ǯ��
//���� level�� ������
//6���� ��带 �� ������ �� (bfs)

//���� ����
int matrix[101][101];//�ܹ��� �׷���
int check[101];//�湮 üũ �迭

int node; //�ִ� 100��
int edge; //�ִ� 2000��

int base_node;

//�Լ� ����
//1��
void dfs_max(int start, int weight, int level)
{
	//start node, base node, weight, level height
	int dist;
	check[start] = 1;

	//�湮
	for (dist = 1; dist <= node; dist++)
	{	//������� �ڽ��� �ƴ� ��, INF�� �ƴϰ� �湮���� �ʾҴٸ�
		if (matrix[start][dist] >= weight && matrix[start][dist] != INF && check[dist] == 0)
		{
			dfs_max(dist, weight, level + 1);
			//ǥ��
			matrix[base_node][dist] = level + 1;
		}
	}

}

void dfs_min(int start, int weight, int level)
{
	//start node, base node, weight, level height
	int dist;
	check[start] = 1;

	//�湮
	for (dist = 1; dist <= node; dist++)
	{	//������� �ڽ��� �ƴ� ��, INF�� �ƴϰ� �湮���� �ʾҴٸ�
		if (matrix[start][dist] <= weight && matrix[start][dist] != INF && check[dist] == 0)
		{
			dfs_min(dist, weight, level + 1);
			//ǥ��
			matrix[base_node][dist] = -(level + 1);
		}
	}

}


//dfs or bfs or �÷��̵� ����
int main()
{
	// freopen("input.txt", "r", stdin);

	int i, j;
	int start = 0, end = 0;
	scanf("%d", &node);
	scanf("%d", &edge);

	//1��
	for (i = 1; i <= node; i++)
	{
		for (j = 1; j <= node; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			//���� ����ġ
			matrix[i][j] = INF;
		}
	}

	//�������
	for (i = 0; i < edge; i++)
	{
		scanf("%d %d", &start, &end);
		// start -> end
		//���⿡�� �ڽ��� ���� elemant�̴�.
		matrix[start][end] = 1; //�� index elemant ���� ������� ������
		matrix[end][start] = -1;
	}


	//dfs
	for (i = 1; i <= node; i++)
	{
		base_node = i; //base node
		dfs_max(i,  1, 1); //start node, weight, level
		memset(check, 0, sizeof(char) * 101);
		dfs_min(i, -1, 1);//start node, weight, level
		//�ʱ�ȭ
		memset(check, 0, sizeof(char) * 101);
	}

	int cnt = 0;
	for (i = 1; i <= node; i++)
	{
		cnt = 0;
		for (j = 1; j <= node; j++)
		{
			if (matrix[i][j] == INF) cnt++;
		}
		printf("%d\n", cnt);
	}


	return 0;
}

*/