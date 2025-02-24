#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int in;
	int max_in;
	int max = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> in;
		if (in > max)
		{
			max = in;
			max_in = i+1;
		}
	}
	cout << max << '\n' << max_in;
	return 0;
}