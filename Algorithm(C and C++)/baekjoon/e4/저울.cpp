#include<iostream>

using namespace std;

int matrix[101][101];//���� ���

int main()
{
	freopen("input.txt", "r", stdin);

	int node; //�ִ� 100��
	int edge; //�ִ� 2000��
	int start=0, end=0;
	scanf("%d", &node);
	scanf("%d", &edge);

	//������� 
	for (int i = 0; i < edge; i++)
	{
		scanf("%d %d", &start, &end);
		//���� ���� �ڽź��� ũ�� 
		//���ڰ� Ŭ���� �ڽź��� �۴�.
		//���⿡�� �ڽ��� ���� elemant�̴�. 
		matrix[start][end] = 1; //�� index elemant ���� ������� ������
		matrix[end][start] = -1; //�� index elemant ���� ������� ū��? 
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