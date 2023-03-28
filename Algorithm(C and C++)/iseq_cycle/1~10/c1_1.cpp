#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;
	int sum = 0;
	scanf("%d %d", &a, &b);

	sum = a + b;

	printf("%d", sum);

	return 0;
}