#include<stdio.h>

static int bic_sub=0;

int three(int i)
{
	int th = (i * i * i);
	bic_sub += th;
	if (i == 1) return bic_sub;
	else three(i - 1);
}

int main()
{
	int i;

	scanf("%d", &i);

	printf("%d", three(i));
}