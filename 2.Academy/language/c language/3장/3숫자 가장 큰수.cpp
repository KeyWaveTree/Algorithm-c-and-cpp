#include<stdio.h>

int main()
{

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	printf("%d", ((a > b) && (a > c) ? a : (b > c) ? b : c));
}