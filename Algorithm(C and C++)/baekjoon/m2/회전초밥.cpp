#include<iostream>

using namespace std;

int check[30001];
int arr[30001];
int main()
{
	//���Ʈ ���� - 1
	//���� �� n, �ʹ��� ���� �� d, �����ؼ� �Դ� ���� k, ���� ��ȣ  
	int n, d, k, c;
	int i, j;
	int flag;
	int sum=0;
	scanf("%d%d%d%d", &n, &d, &k, &c);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int coupon = c;
	for (i = 0; i < n; i++)
	{
		flag = 0;
		for (int j = i; j < i + k; j++)
		{
			if (check[arr[j % n]] == 1) flag++; // �̹� ���� �ʹ��� ��� �ߺ� �� ǥ��	
			else check[arr[j % n]] = 1; // ó�� �Ծ�� �ʹ��� ��� üũ		

			if (arr[j % n] == c) coupon = 0; // ���� ���� ���� ��
		}
		sum = max(sum, k - flag + coupon); //�������� ���� �� �ִ� �ִ����� - �ߺ����� + ��������	
		memset(check, 0, sizeof(check)); // üũ �ʱ�ȭ
	}

	// ������ ��� - 2
	// �迭�� ���� �� �ε��� ��ҿ� ���Ѵ� +1 
	// K+1�� ���� �ε��� ��Ҵ� +1�ϰ� 
	// k+1-k�� �� �ε��� ��Ҵ� �����ش�. 0���� �����. 
	// ������ �ε��� ��ġ�� 1�� ��� �־��ش�. 
	// ���ڸ��� ���� k�϶� cnt�� +1�Ѵ�.
}