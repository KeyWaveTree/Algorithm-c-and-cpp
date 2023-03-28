#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[100] = { 0 };
	int max = 0;

	for (int i = 0;i<2; i++)
	{
		for (int k = 0, j=-1;; k++) {
			scanf("%d", &j);
			if (j == 0) break;
			if (max < j) max = j;
			arr[j] += 1;
		}
	}
	
	//교집합
	for (int i = 1; i <= max; i++)
	{
		if (arr[i] > 1) printf("%d\t", i);
	}
	printf("\n");
	
	//합집합
	for (int i = 1; i <= max; i++)
	{
		if (arr[i] >= 1) printf("%d\t", i);
	}
	printf("\n");

	return 0;
}