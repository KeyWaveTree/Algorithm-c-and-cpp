#include<iostream>

using namespace std;

int matrix[101][101];//인접 행렬

int main()
{
	freopen("input.txt", "r", stdin);

	int node; //최대 100개
	int edge; //최대 2000개
	int start=0, end=0;
	scanf("%d", &node);
	scanf("%d", &edge);

	//인접행렬 
	for (int i = 0; i < edge; i++)
	{
		scanf("%d %d", &start, &end);
		//작을 수록 자신보다 크고 
		//숫자가 클수록 자신보다 작다.
		//여기에서 자신은 현재 elemant이다. 
		matrix[start][end] = 1; //행 index elemant 보다 몇번으로 작은가
		matrix[end][start] = -1; //행 index elemant 보다 몇번으로 큰가? 
	}

	for (int i = 1; i <= node; i++)
	{
		for (int j = 1; j <= node; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}