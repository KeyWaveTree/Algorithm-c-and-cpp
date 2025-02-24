#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;

	scanf("%d %d", &n, &m);

	if (n > m) printf("%d", n);
	else printf("%d", m);
}