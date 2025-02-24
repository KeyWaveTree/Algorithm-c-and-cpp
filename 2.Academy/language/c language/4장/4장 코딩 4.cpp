#include<stdio.h>
int main()
{
	freopen("c.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b, c;
	float sum = 0;
	float avr;

	scanf("%d %d %d", &a, &b, &c);

	sum = a + b + c;
	avr = sum / 3;
	printf("%.2f %.2f", sum, avr);
}