#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	int value, m1=0, m2=1;
	scanf("%d", &n);

	for (int i = 1; i < n; i++)
	{
		value = m1 + m2;
		m1 = m2;
		m2 = value;
	}
	printf("%d", value);
}