#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000001];

int main()
{
	int i = 0;
	int n;
	int index = 0;
	cin >> n;

	for (i = 2; i <=n; i++)
	{
		
		if (i % 6 == 0)
		{
			dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3])) + 1;
		}

		else if (i % 3 == 0)
		{
			dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
		}
		else if (i % 2 == 0)
		{
			dp[i] = min(dp[i / 2], dp[i-1]) + 1;
		}
		else dp[i] = dp[i - 1] + 1;
	}

	cout << dp[n];

	return 0;
}