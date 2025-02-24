#include<iostream>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

point bundle[101];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, t, k;
	int i, j, q;
	int w, h;
	int max = 0;
	int cnt = 0;
	int max_x=0, max_y=0;

	scanf("%d%d%d%d", &n, &m, &t, &k);

	for (i = 1; i <= t; i++)
	{
		scanf("%d %d", &bundle[i].x, &bundle[i].y);
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			w = bundle[i].x;
			h = bundle[j].y;

			cnt = 0;
			for (q = 1; q <= t; q++)
			{
				if (w <= bundle[q].x && bundle[q].x <= w + k && h - k <= bundle[q].y && bundle[q].y <= h) cnt++;
			}

			if (max < cnt)
			{
				max_x = w;
				max_y = h;
				max = cnt;
			}
		}
	}

	if (max_x + k > n) max_x = n - k;
	if (max_y - k < 0) max_y = k;

	printf("%d %d\n", max_x, max_y);
	printf("%d", max);

	return 0;
}