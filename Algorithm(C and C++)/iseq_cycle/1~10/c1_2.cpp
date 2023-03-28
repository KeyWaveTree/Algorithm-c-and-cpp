#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\t", a + b);
	printf("%d\t", a - b);
	printf("%d\t", a * b);
	printf("%d\t", a / b);
}