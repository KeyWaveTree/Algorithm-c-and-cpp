#include<iostream>
#include<algorithm>

using namespace std;

typedef struct point 
{
	int x;
	int y;
};

point arr[100];
int dp[100];

bool compare(const point& a, const point& b)
{
	return a.x < b.x;
}

int main()
{
	int n;
	int max_dp=0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + n, compare);

	dp[0] = 1;
	//lis
	for (int i = 1; i < n; i++)
	{
		dp[i] = 1; //항상 자신만은 최대크기가 1
		for (int j = i-1; j >= 0; j--)
		{
			if (arr[j].y < arr[i].y)
			{
				dp[i] = max(dp[j] + 1, dp[i]);
			}
			if (max_dp < dp[i]) max_dp = dp[i];
		}
	}

	printf("%d", n - max_dp);

	return 0;
}