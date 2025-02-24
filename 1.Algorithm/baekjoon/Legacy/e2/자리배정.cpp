#define _CRT_SECURE_NO_WARNING
#include<iostream>

using namespace std;

int sit[1000][1000];

int main()
{
	int c, r; //가로, 세로
	int cc = 0, rr = 0; //가로, 세로 감소값

	int cnt = 0;
	int sw = 1;
	int flag = 0;
	int i, j;
	int ii = 0, jj = -1;
	int sit_num;

	cin >> c >> r;
	cin >> sit_num;

	cc = c, rr = r;
	while (1)
	{
		for (i = 0; i < rr; i++)
		{
			jj += sw;
			sit[ii][jj] = ++cnt;
			if (cnt == sit_num)
			{
				flag = 1;
				break;
			}
		}
		if (flag) break;
		cc--;
		for (j = 0; j < cc; j++)
		{
			ii += sw;
			sit[ii][jj] = ++cnt;
			if (cnt == sit_num)
			{
				flag = 1;
				break;
			}
		}
		if (flag) break;
		rr--;
		sw *= -1;
	}
	if (flag)
	{
		printf("%d %d", ii + 1, jj + 1);
	}
	else
	{
		cout << 0;
	}

	return 0;
}