#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int row;

	scanf("%d", &n);

	row = n * 4 / 3;

	printf("%d", row);

	return 0;
}