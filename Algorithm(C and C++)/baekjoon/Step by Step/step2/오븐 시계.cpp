#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int a, b, c;
	scanf("%d %d", &a, &b);
	scanf("%d", &c);

	b += c;

	if (b > 59)
	{
		a += (b) / 60;
		b = (b) % 60;

		if (a > 23)
		{
			a -= 24;
		}
		cout << a << " " << b;
	}
	else
	{
		cout << a << " " << b;
	}
	return 0;
}