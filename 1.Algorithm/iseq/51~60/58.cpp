#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m, x;
	int mok, na;

	scanf("%d%d%d", &n, &m, &x);
	mok = n/m;
	na = n % m * 10;
	printf("%d", mok);
	printf(".");
	for (int i = 0; i < x; i++)
	{
		mok = na / m;
		printf("%d", mok);
		na = na % m * 10;	
	}

	return 0;
}