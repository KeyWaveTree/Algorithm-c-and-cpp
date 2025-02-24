#include<iostream>

using namespace std;

int main()
{
	int arr[100] = { 0 };
	int n;
	int number;
	int temp;

	cin >> n;
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> number;
		for (int j = i; j>= i - number; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[i - number-1] = i;
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
}

//int arr[101] = { 0 };
//int n;
//int L;
//int number;
//
//void checkSWAP(int exp)
//{
//	int temp;
//	for (int j = 1; j <= L; j++)
//	{
//		if (arr[L - number + j] != 0)//넣을때 값이 있을때
//		{
//			temp = exp;
//			exp = arr[L - number + j];
//			arr[L - number + j] = temp;
//
//		}
//		else if (arr[L - number + j] == 0)
//		{
//			arr[L - number + j] = exp;
//			break;
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	arr[1] = 1;
//	for (int i = 2; i <= n; i++)
//	{
//		cin >> number;
//		L++;
//		arr[0] = arr[L - number];
//		arr[L - number] = i;
//		//값 바꾸기
//		checkSWAP(arr[0]);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	return 0;
//}