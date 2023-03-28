#include<stdio.h>
#include<iostream>

using namespace std;

int isAmTrue(int n)
{
	int sum = 0;
	int m = n;
	if (m == 0) return 1;
	while (m > 0)
	{
		sum += (m % 10) * (m % 10) * (m % 10);
		m /= 10;
	}

	//예비 암스트롱수와 각 자리에 세제곱한 값이 같다면 암스트롱 수 
	return n==sum;
}

int main()
{
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 1000; i++)
	{
		if (isAmTrue(i))
		{
			printf("%d\n", i);
		}
	}

	return 0;
}