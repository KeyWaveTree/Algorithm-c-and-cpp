#include<iostream>

using namespace std;

int main()
{
	//ù��° Ʋ�� ���� min���� ������ �ִ밪���� �����ؼ� �׷��� ����.
	//���� ã��: �ִ밪�� 20�� ���� �����⿡ �� int max������ ������ ��� ��
	/*
	int n, x;
	int a;
	int min = 1e+9;
	scanf("%d%d", &n, &x);
	int temp = min;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if ((a*x) + (temp*x) < min) min = (a * x) + (temp * x);
		temp = a;
	}
	printf("%d", min);
	return 0;
	*/

	int n, x;
	int a[100000];
	int min;
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	min = 21e+8;

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] * x + a[i + 1] * x < min) min = a[i] * x + a[i + 1] * x;
	}

	printf("%d", min);
	return 0;
}
