#include<iostream>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	int x, y;
	bool flag = false;
	cin >> a >> b >> c >> d >> e >> f;

	for (x = -999; x <= 999; x++)
	{
		for (y = -999; y <= 999; y++)
		{
			if ((a*x)+(b*y)==c &&(d*x)+(e*y)==f) 
			{
				flag = true;
				break;
			}
		}
		if (flag) break;
	}

	printf("%d %d", x, y);

	return 0;
}