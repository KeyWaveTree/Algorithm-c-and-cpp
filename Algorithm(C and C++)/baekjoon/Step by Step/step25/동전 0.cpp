#include<iostream>

using namespace std;

int main()
{

	freopen("input.txt", "r", stdin);

	int arr[10] = { 0 };

	int n; 
	int k;
	int min_cnt = 0;

	scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = n - 1; i >= 0; i--)
	{
		if (arr[i] > k) continue;
		min_cnt += k / arr[i];
		k %= arr[i];
	}

	printf("%d", min_cnt);
	return 0;
}