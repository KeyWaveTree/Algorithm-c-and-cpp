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
	if (n == i) printf("�Ҽ�");
	else printf("�Ҽ��� �ƴ�");

	return 0;
}