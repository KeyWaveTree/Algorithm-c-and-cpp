#include<stdio.h>

int main()
{
	int n;
	int next, fibo, add;
	scanf("%d", &n);

	fibo =0;
	next = 1;

	for (int i = 0; i < n+1; i++)
	{
		printf("%d, ", fibo); 
		
		add = fibo + next;
		fibo = next;
		next = add;
	}

	return 0;
}