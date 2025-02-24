#include<stdio.h>

int gcd(int i, int j)
{
	//1
	/*if (j == 0) return i;
	else return gcd(j, i % j);*/

	//2
	return j ? gcd(j, i % j) : i;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d", gcd(a, b));
}