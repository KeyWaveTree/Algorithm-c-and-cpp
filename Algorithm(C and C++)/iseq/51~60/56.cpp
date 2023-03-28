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

	//���� �Ͻ�Ʈ�ռ��� �� �ڸ��� �������� ���� ���ٸ� �Ͻ�Ʈ�� �� 
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