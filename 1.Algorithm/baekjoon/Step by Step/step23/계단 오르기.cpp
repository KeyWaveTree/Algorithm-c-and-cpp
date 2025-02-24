#include<iostream>

using namespace std;

int arr[301] = { 0 }; //점수 목록
int n;
int dp[301];
int floar(int k)
{	
	if (k == 1)
		return arr[1];
	if (k == 2)
		return arr[1] + arr[2];
	if (k == 3)
		return max(arr[1] + arr[3], arr[2] + arr[3]);

	if (dp[k] != 0)
		return dp[k];

	dp[k] = max(floar(k - 2) + arr[k], floar(k - 3) + arr[k - 1] + arr[k]);
	return dp[k];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i;
	int sum=0;

	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
	}

	// ...

	//for (i = 4; i <= n; i++) {
	//	dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	//}

	sum = floar(n);
	printf("%d", sum);
}