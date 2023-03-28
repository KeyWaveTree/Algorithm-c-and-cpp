#include<stdio.h>
#include<iostream>

using namespace std;

int fibonacci(int m)
{
	if (m == 1) return 1;
	if(m==0) return 0;
	else return m +fibonacci(m - 1);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d", &n);

	int value=fibonacci(n);
	printf("%d", value);
}