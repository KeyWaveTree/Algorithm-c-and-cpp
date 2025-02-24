#include<iostream>
using namespace std;

int pan[5][5] = { 0 };
int check[5][5] = { 0 };

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int i, j, k;
	int p_x, p_y;
	bool l = true, r = true;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			scanf("%d", &pan[i][j]);
		}
	}

	int cnt = 0;
	int c;
	for (i = 1; i <= 25; i++)
	{
		scanf("%d", &n);
		for (j = 0; j < 5; j++)
		{
			for (k = 0; k < 5; k++)
			{
				if (pan[j][k] == n)
				{
					p_x = j;
					p_y = k;
					check[j][k] = 1;
				}
			}
		}
		
		//4가지 
		//행 체크
		c = 0;
		for (j = 0; j < 5; j++)
		{
			if (check[p_x][j] == 1) c++;
		}
		if (c==5)cnt++;
		if (cnt == 3)
		{
			printf("%d", i);
			return 0;
		}

		//열 체크 
		c = 0;
		for (j = 0; j < 5; j++)
		{
			if (check[j][p_y] == 1) c++;
		}
		if (c == 5)cnt++;
		if (cnt == 3)
		{
			printf("%d", i);
			return 0;
		}
		
		//왼->오아래 대각선 체크
		c = 0;
		for (j = 0; j < 5; j++)
		{
			if (check[j][j] == 1 && l) c++;
		}
		if (c == 5) {
			l = false;
			cnt++;
		}
		if (cnt == 3)
		{
			printf("%d", i);
			return 0;
		}
		
		//오->왼아래 대각선 체크
		c = 0;
		for (j = 0; j < 5; j++)
		{
			if (check[j][4-j] == 1 && r) c++;
		}
		if (c == 5)
		{
			r = false;
			cnt++;
		}
		if (cnt == 3)
		{
			printf("%d", i);
			return 0;
		}
	}
	
	return 0;
}