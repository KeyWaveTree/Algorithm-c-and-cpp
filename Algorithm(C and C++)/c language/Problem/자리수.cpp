#include<stdio.h>

int main()
{
	int n;
	int cnt = 0;
	scanf("%d", &n);

	do
	{
		cnt++;
		n /= 10;
	} while (n != 0);

	printf("%d", cnt);
}