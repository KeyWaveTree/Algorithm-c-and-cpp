#include<iostream>

using namespace std;

int dp[41];
int re_cnt = 0;
int fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		re_cnt++;
		return 1;
	}
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int dp_fibonacci(int n)
{
	int cnt = 0;
	dp[0] = 0;
	dp[1] = dp[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		cnt++;
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	return cnt;
}

int main()
{

}