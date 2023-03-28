#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);
	
	int num, n;
	scanf("%d %d", &num, &n);
	printf("%d", (1 << n) | num);
}