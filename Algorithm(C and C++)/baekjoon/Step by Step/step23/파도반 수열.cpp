#include<iostream>

using namespace std;

long long dp[101];

int main()
{
	int t;
	int n;
	scanf("%d", &t);
	dp[0] = 0;
	dp[1] = dp[2] =dp[3]= 1;
	
	
	for (int i = 4; i <= 100; i++)
	{
		dp[i] = dp[i - 2] + dp[i - 3];
	}

	for (int i = 0; i < t; i++)
	{
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}