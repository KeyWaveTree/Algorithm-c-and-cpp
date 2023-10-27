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

	//색종이 표시 - 1 
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

	//외각선, 내각선
	for (i = 1; i <= 100; i++)
	{
		for (j = 1; j <= 100; j++)
		{
			//탐색을 하다가 면적에 도달했다면 
			if (arr[i][j] == 1)
			{
				//상하좌우 - 여백이 있다면 둘레부분에 있다는 것으로 
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