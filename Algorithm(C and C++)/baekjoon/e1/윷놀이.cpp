#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char o[5] = { 'D', 'C', 'B', 'A', 'E'};
	int a, b, c, d;
	for (int i = 0; i < 3; i++)
	{
		cin >> a >> b >> c >> d;
		cout << o[a + b + c + d]<<'\n';
	}
	return 0;
}