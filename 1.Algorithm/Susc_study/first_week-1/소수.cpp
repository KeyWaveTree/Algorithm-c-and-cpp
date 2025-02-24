#include<iostream>

using namespace std;

int main()
{
	int a, b, n;
	int i;
	int mok, na;
	scanf("%d%d%d", &a, &b, &n);

	mok = a % b;
	na = mok % b * 10;
	for (i = 0; i < n; i++)
	{
		mok = na / b;
		na = na % b * 10;
	}
	printf("%d", mok);

	return 0;
}