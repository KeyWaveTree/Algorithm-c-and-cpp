#include<stdio.h>

int main()
{
	int arr[100] = { 0 };

	int n;
	int din;
	int temp = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("���� �ε��� ��ġ");
	scanf("%d", &din);
	for (int i = 0; i < n; i++)
	{
		if (i == din) continue;
		printf("%d ", arr[i]);
	}

	return 0;
}