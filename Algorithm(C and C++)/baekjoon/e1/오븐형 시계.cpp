#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b, c;
	int m=0;
	cin >> a >> b;
	cin >> c;
	
	b += c;
	if (b >= 60)
	{
		m = b % 60;
		a += b / 60;
		if (a >= 24)
		{
			a %= 24;
		}
		b = m;
	}

	cout << a << " " << b;

	return 0;
}