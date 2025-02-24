#include<iostream>

using namespace std;

int main()
{
	//첫번째 틀림 이유 min값을 임의의 최대값으로 선택해서 그런것 같음.
	//이유 찾음: 최대값이 20억 정도 나오기에 약 int max값으로 지정해 줘야 함
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
