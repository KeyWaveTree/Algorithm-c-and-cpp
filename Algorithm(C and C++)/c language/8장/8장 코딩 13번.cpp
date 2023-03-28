#include<stdio.h>

int show_digit(int x)
{
	 if (x % 10 == 0) return 0;
	 show_digit(x / 10);
	 printf("%d",x%10);
	 
}

int main()
{
	int n;

	scanf("%d", &n);

	show_digit(n);
}