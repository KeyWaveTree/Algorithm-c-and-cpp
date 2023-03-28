#include<stdio.h>

int n;

void nagative(int* arr)
{
	for (int i = n-1; i >=0; i--)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{	
	int arr[100] = { 0 };
	

	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &arr[i]);
	}
	
	nagative(arr);
}