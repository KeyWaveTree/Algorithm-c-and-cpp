#include<stdio.h>

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		if (n % i) break;
	}
	if (n == i) printf("소수");
	else printf("소수가 아님");

	return 0;
}