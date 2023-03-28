#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);

	int x, y;
	int sum = 0;
	scanf("%d%d", &x, &y);

	for (x; x <= y;x++)
	{
		sum += x;
	}

	printf("%d", sum);
	return 0;
}