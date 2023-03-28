#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;

	for (int i = 0; i < 3; i++)
	{
		scanf("%d", &n);
		if (n % 2 == 0) printf("Â¦¼ö");
		else printf("È¦¼ö");
	}
}