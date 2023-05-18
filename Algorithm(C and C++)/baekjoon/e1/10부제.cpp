#include<iostream>

using namespace std;

int main()
{
	int car;
	int n;
	int cnt = 0;

	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &car);
		if (car == n)cnt++;
	}
	printf("%d", cnt);
	return 0;
}