#include<iostream>

using namespace std;

int arr[1000000];
int dp[1000000];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int max = 1;
	int cnt = 1;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		dp[arr[i]-1] = i;
	}

	for (int i = 1; i < n; i++)
	{
		if (dp[i] > dp[i - 1]) cnt++;
		else cnt = 1;
		if (max < cnt) max = cnt;
	}

	printf("%d", n - max);

	return 0;
}