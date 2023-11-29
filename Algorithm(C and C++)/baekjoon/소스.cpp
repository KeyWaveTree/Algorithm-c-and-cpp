#include<stdio.h>

void f(int* x, int y)
{
	(*x)++; y++;
	
}

int main()
{
	int a = 1;
	int b = 2;
	f(a, b);
}