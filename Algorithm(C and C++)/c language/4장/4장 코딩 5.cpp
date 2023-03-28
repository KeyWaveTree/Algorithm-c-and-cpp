#include<stdio.h>
int main()
{
	freopen("c.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d %d", a / b, a % b);

}