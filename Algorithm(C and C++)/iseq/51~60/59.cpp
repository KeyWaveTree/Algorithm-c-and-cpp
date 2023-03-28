#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[100] = { 0 };
	int n;
	int i = 0;

	scanf("%d", &n);
	while (1)
	{
		arr[i] = n % 2;
		n /= 2;
		if (n == 0 || n == 1) break;
		i++;
	}

	printf("%d", n);
	for (; i >= 0; i--) {
		printf("%d", arr[i]);
	}
}