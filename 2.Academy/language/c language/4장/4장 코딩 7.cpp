#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);

	float x;
	scanf("%f", &x);

	float fx = ((x * x * x) - 20) / (x - 7);
	printf("%f", fx);
}