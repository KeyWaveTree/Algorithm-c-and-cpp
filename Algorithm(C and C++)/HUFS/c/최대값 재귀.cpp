#include<iostream>

int rfindmax(int* arr, int n)
{
	if (n == 1) return arr[0];

	else
	{
		int max = rfindmax(arr, n - 1);
		if (max < arr[n-1]) return arr[n-1];
		else return max;
	}
}

int main()
{
	int arr[10] = { 10, 39 , 50, 20, 30, 10, 30, 60, 59, 32};

	printf("%d", rfindmax(arr, 10));

}