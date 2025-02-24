#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 20

int w, h, A[N][N];
int count;
// 전역은 0으로 초기화가 된다.

void input()
{
	scanf("%d%d", &w, &h);
	A[w][h] = 1;
}

void run()
{
	while (1) {
		count++;
		for (h = 1; h < N; h++)
		{
			for (w = 1; w < N; w++)
			{
				if (A[h][w] == count)
				{
					if (!A[h - 1][w] && h - 1 > 0)A[h - 1][w] = count+1;
					if (!A[h][w + 1] && w + 1 < N)A[h][w + 1] = count+1;
					if (!A[h + 1][w] && h + 1 < N)A[h + 1][w] = count+1;
					if (!A[h][w - 1] && w - 1 > 0)A[h][w - 1] = count + 1;

					/*for (int k = 0; k <= 3; k++)
					{
						if (!A[h + C[k][w + D[k] && h + C[k] > 0 && h + C[k] < N && w + D[k]>0 && w + D[k] < N) 
						{
							A[h+C[k][w+D[k]]=2;					
						}
					}*/

				}
			}
		}
		if (count == 5)
		{
			break;
		}
	}
}

void print()
{
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++) 
		{
			printf("%3d", A[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	input();
	run();
	print();
	return 0;
}