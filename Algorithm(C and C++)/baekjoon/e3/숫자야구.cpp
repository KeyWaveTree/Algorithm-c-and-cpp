#include<iostream>

using namespace std;

struct q
{
	int k;
	int s, b;
}q[101];

int main()
{
	int i1, i2, i3;
	int i, n;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d %d%d", &q[i].k, q[i].s, q[i].b);
	}

	int cnt = 0;
	int s, b;
	int k1, k2, k3;
	for (i1 = 1; i1 <= 9; i1++)
	{
		for (i2 = 1; i2 <= 9; i2++)
		{
			for (i3 = 1; i3 <= 9; i3++)
			{
				if (i1 == i2 || i1 == i3 || i2 == i3) continue;

				for (i = 1; i <= n; i++)
				{
					s = 0, b = 0;
					k1 = q[i].k / 100;
					k2 = q[i].k / 100 / 10;
					k3 = q[i].k % 10;

					if (k1 == i1)s++;
					if (k2 == i2)s++;
					if (k3 == i3)s++;
					if (k1 == i2 || k1 == i3) b++;
					if (k2 == i1 || k2 == i3) b++;
					if (k3 == i1 || k3 == i2) b++;
					if (s != q[i].s || b != q[i].b) break;
				}

				if (n == i - 1)cnt++;
			}
		}
	}

}