#include<iostream>

using namespace std;


int arr[102][102];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	int x, y;
	int i, j, k;
	int cnt = 0;
	scanf("%d", &n);

	//������ ǥ�� - 1 
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = y+1; j < y+ 11; j++)
		{
			for (k= x+1; k < x + 11; k++)
			{
				arr[j][k] = 1;
			}
		}
	}

	//�ܰ���, ������
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 100; j++)
		{
			//Ž���� �ϴٰ� ������ �����ߴٸ� 
			if (arr[i][j] == 1)
			{
				//�����¿� - ������ �ִٸ� �ѷ��κп� �ִٴ� ������ 
				if (arr[i + 1][j] == 0 && i+1 <= 100) cnt++;
				if (arr[i - 1][j] == 0 && i-1 >= 0) cnt++;
				if (arr[i][j - 1] == 0 && j-1 >= 0) cnt++;
				if (arr[i][j + 1] == 0 && j+1 <=100) cnt++;
			}
		}
	}	

	printf("%d", cnt);
	return 0;
}