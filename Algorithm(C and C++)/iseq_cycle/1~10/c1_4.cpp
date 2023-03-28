#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, m;
	int t, r;
	scanf("%d%d", &n, &m);

	//삼각형
	//사각형
	r = n * m;
	t = r / 2;

	printf("%d %d", t, r);

	return 0;
}