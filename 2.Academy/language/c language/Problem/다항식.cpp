#include<stdio.h>
int main()
{
	double x;

	scanf("%lf", &x);

	double num = 3 * (x * x * x) - 7 * (x * x) + 9;

	printf("%.2lf", num);
}