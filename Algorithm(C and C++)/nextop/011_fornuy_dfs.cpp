#define _CRT_SECURE_NO_WARNINGS
#define N 10
#include<stdio.h>
#include<iostream>

using namespace std;

int n = N;
int a[10][10];

void print()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%3d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void q(int h, int w, int v)
{
	if (a[h][w] != 0 ||h<=0 || w<=0 || h>n || w>n ) return;

	a[h][w] = v;

	if (h == n && w == n)
	{
		print();
		// �̰��� ������ 4���Ҷ� ���� �ִ������� �ν��ϱ⿡ ���ڸ����� �ʱ�ȭ�� ����� �Ѵ�.
		a[h][w] = 0;
		return;
	}

	q(h + 1, w, v + 1);
	q(h, w + 1, v + 1);
	q(h - 1, w, v + 1);
	q(h, w - 1, v + 1);

	a[h][w] = 0;
}


int main()
{
	freopen("output.txt", "w", stdout);

	q(1, 1, 1);

	return 0;
}