#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);

	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);
	int max = (a > b) && (a>c) ? a : ((b > c) ? b : c);
	printf("%d", max);
}