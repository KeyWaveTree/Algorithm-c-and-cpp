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

이 경우 일 때 내가 작성한 코드를 보자 
#include<iostream>
#include<cstring>
#define INF 987654321

using namespace std;
//1번 풀이
//dfs로 간 곳 표시

//2번 풀이
//같은 level에 있으면
//6개의 노드를 다 돌려야 함 (bfs)

//전역 변수
int matrix[101][101];//단방향 그래프
int check[101];//방문 체크 배열

int node; //최대 100개
int edge; //최대 2000개

int base_node;

//함수 선언
//1번
void dfs_max(int start, int weight, int level)
{
	//start node, base node, weight, level height
	int dist;
	check[start] = 1;

	//방문
	for (dist = 1; dist <= node; dist++)
	{	//인접행렬 자신이 아닌 값, INF가 아니고 방문하지 않았다면
		if (matrix[start][dist] >= weight && matrix[start][dist] != INF && check[dist] == 0)
		{
			dfs_max(dist, weight, level + 1);
			//표시
			matrix[base_node][dist] = level + 1;
		}
	}

}

void dfs_min(int start, int weight, int level)
{
	//start node, base node, weight, level height
	int dist;
	check[start] = 1;

	//방문
	for (dist = 1; dist <= node; dist++)
	{	//인접행렬 자신이 아닌 값, INF가 아니고 방문하지 않았다면
		if (matrix[start][dist] <= weight && matrix[start][dist] != INF && check[dist] == 0)
		{
			dfs_min(dist, weight, level + 1);
			//표시
			matrix[base_node][dist] = -(level + 1);
		}
	}

}


//dfs or bfs or 플로이드 워셜
int main()
{
	// freopen("input.txt", "r", stdin);

	int i, j;
	int start = 0, end = 0;
	scanf("%d", &node);
	scanf("%d", &edge);

	//1번
	for (i = 1; i <= node; i++)
	{
		for (j = 1; j <= node; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				continue;
			}

			//무한 가중치
			matrix[i][j] = INF;
		}
	}

	//인접행렬
	for (i = 0; i < edge; i++)
	{
		scanf("%d %d", &start, &end);
		// start -> end
		//여기에서 자신은 현재 elemant이다.
		matrix[start][end] = 1; //행 index elemant 보다 몇번으로 작은가
		matrix[end][start] = -1;
	}


	//dfs
	for (i = 1; i <= node; i++)
	{
		base_node = i; //base node
		dfs_max(i,  1, 1); //start node, weight, level
		memset(check, 0, sizeof(char) * 101);
		dfs_min(i, -1, 1);//start node, weight, level
		//초기화
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