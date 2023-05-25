#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	int cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) cnt++;
		if (n % i == 0 && cnt == k)
		{
			cout << i;
			return 0;
		}
	}
	cout << 0;

	return 0;
}