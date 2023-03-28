#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[10][10] = { 0 };
	int n;
	int cnt = 0;
	int i = 0, j = 1;
	int ii, jj, nn;
	int sw = 1;
	scanf("%d", &n);

	ii = i; jj = j; nn = n;
	while (cnt<=nn*nn)
	{
		for (i = 0; i < n; i++)
		{
			ii+=sw;
			arr[jj][ii] = ++cnt;
		}
		n--;
		if (n == 0) break;

		for (j = 0; j < n; j++)
		{
			jj += sw;
			arr[jj][ii] = ++cnt;
		}
		sw *= -1;
	}
	
	for(i = 1; i <= nn; i++)
	{
		for (j = 1; j <= nn; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}