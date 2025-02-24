#include<iostream>

using namespace std;

int main()
{
	//long long ¶§¹®¿¡ 
	long long dp[91] = { 0, 1 };
	int n;
	int i;
	for (i = 2; i <= 90; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	scanf("%d", &n);
	

	printf("%lld", dp[n]);

	return 0;
}