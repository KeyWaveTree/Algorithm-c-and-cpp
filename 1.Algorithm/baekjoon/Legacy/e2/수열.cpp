#include<iostream>

using namespace std;

int arr[100000];

//1锅掳 规过
int main()
{
	int n, i;
	int check = -9999999;
	int max = 0;
	int min = 0;
	int max_cnt = 0;
	int min_cnt = 0;

	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (i = 0; i < n; i++)
	{
		if (arr[i] == check)
		{
			max_cnt++;
			min_cnt++;
			if (min < min_cnt)min = min_cnt;
			if (max < max_cnt)max = max_cnt;

		}
		if (arr[i] > check)
		{
			max_cnt++;
			if (min < min_cnt)min = min_cnt;
			if (max < max_cnt)max = max_cnt;
			min_cnt = 1;
		}
		else if (arr[i] < check)
		{
			min_cnt++;
			if (max < max_cnt)max = max_cnt;
			if (min < min_cnt)min = min_cnt;
			max_cnt = 1;
		}

		check = arr[i];
	}

	printf("%d", (max > min) ? max : min);
	return 0;
}

// 2锅掳 规过
//#include<iostream>
//
//using namespace std;
//
//int arr[100000];
//
//int main()
//{
//	int n;
//	int i;
//	int check = -9999999;
//	int cnt = 0;
//	int max1 = 0;
//	int max2 = 0;
//
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		cin >> arr[i];
//	}
//
//	for (i = 0; i < n; i++)
//	{
//		if (arr[i] >= check)
//		{
//
//			cnt++;
//			if (max1 < cnt)max1 = cnt;
//		}
//		else if (arr[i] < check)
//		{
//			if (max1 < cnt)max1 = cnt;
//			cnt = 1;
//		}
//		check = arr[i];
//	}
//
//	check = -9999999;
//	cnt = 0;
//	for (i = n - 1; i >= 0; i--)
//	{
//		if (arr[i] >= check)
//		{
//			cnt++;
//			if (max2 < cnt)max2 = cnt;
//		}
//		else if (arr[i] < check)
//		{
//			if (max2 < cnt)max2 = cnt;
//			cnt = 1;
//		}
//		check = arr[i];
//	}
//
//	printf("%d", (max1 > max2) ? max1 : max2);
//	return 0;
//}
