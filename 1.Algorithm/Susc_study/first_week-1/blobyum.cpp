#include<iostream>

using namespace std;

const int SIZE = 200000;

int arr[SIZE];
int main()
{
	int n, k;
	int i;
	int sum = 0;
	int max = 0;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		//��ȯ�� �ؾ� �ϱ⿡ - ������ Ʋ�Ⱦ���.
		arr[n+i] = arr[i];
		if (i + 1 <= k)
		{
			sum += arr[i];
		}
	}
	max = sum;
	
	//���� ��ü�� �¾����� 2*n���� �ؾ� ��. n���� �ϸ� ���� �� ���� ���� ������  
	for (i = k; i <=2*n; i++)
	{
		//������
		//�ڿ� �ִ� �� ���� ���� ��.
		sum -= arr[i - k];
		sum += arr[i];
		if (sum > max) max = sum;
	}

	printf("%d", max);
	return 0;
}