#include<iostream>

using namespace std;

char chess[50][50];
char sw[2];
char temp;

int paintB(int* p1, int* p2)
{
	int i, j;
	int cnt = 0;
	int len = 0;
	sw[0] = 'B', sw[1] = 'W';
	for (i = *p1; i < *p1 + 8; i++)
	{
		for (j = *p2; j < *p2 + 8; j++)
		{
			if (chess[i][j] != sw[len % 2]) cnt++;
			len++;
		}
		temp = sw[0];
		sw[0] = sw[1];
		sw[1] = temp;
	}
	return cnt;
}

int paintW(int *p1, int *p2)
{
	int i, j;
	int cnt = 0;
	int len = 0;
	sw[0] = 'W', sw[1] = 'B';
	for (i = *p1; i < *p1 + 8; i++)
	{
		for (j = *p2; j < *p2 + 8; j++)
		{
			if (chess[i][j] != sw[len % 2]) cnt++;
			len++;
		}
		temp = sw[0];
		sw[0] = sw[1];
		sw[1] = temp;
	}
	return cnt;
}

int main()
{
	freopen("baek_input.txt", "r", stdin);
	int n, m;
	int i, j;
	int checkB=0, checkW=0, check=0;
	int min = 2500;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> chess[i][j];
		}
	}

	for (i = 0; i < (n - 8)+1; i++)
	{
		for (j = 0; j < (m - 8)+1; j++)
		{
			checkB = paintB(&i, &j);
			checkW = paintW(&i, &j);
			check = (checkB > checkW ? checkW : checkB);
			if (min > check) min = check;
		}
	}

	cout << min;

	return 0;
}