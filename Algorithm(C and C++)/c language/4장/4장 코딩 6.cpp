#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);
	int hto;

	scanf("%d", &hto);
	printf("%d\n", hto / 100);
	printf("%d\n", (hto % 100)/10);
	printf("%d\n", (hto % 100) % 10);
}