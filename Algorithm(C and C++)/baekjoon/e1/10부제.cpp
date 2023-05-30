#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int car;
	int n;
	int cnt = 0;

	scanf("%d", &n);
	for(int i=0;i<5;i++)
	{
		scanf("%d", &car);
		if (car == n)cnt++;
	}
	printf("%d", cnt);
	return 0;
}