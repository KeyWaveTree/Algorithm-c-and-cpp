#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[100] = { 1 };
	int n;
	int L = 0, carry, temp;
	scanf("%d", &n);
	
	for (int j = 1; j <= n; j++) 
	{
		//���̴� ������ �ִ°��� �ƴϴ�  L�� ����
		for (int i = 0; i <= L; i++)
		{
			//���� �ڸ��� �� 2
			arr[i] *= 2;
		}

		if (arr[L] >= 10) L++; //������ �迭�� ���� 10���� ũ�� ���� �ϳ� ����
		//(�ǹ�) 1~n���� �ݺ��� ������ ���� 10���ڸ����� ũ�ٸ� ���̸� �ϳ� �����϶� 
		carry = 0;

		for (int i = 0; i <= L; i++)
		{
			//���ڸ� �� ��+ �ø����� ���� ���� - ���� 0�� ������ �ȵȴ�.
			//(why? arr[i]�ٰ� �������� �ʴ°�? - �ø��� ���� �� �� �ս��� �߻��Ѵ�.)
			temp = arr[i] % 10 + carry;
			//���� �ø����� ����� ���� �� - temp������ �����ϸ� temp�� ������ �ȴ�.
			carry = arr[i] / 10;
			//�״��� ��ġ���ٰ� �Ͽ��ڸ� �� ����
			arr[i] = temp;
		}
	}

	for (int i = L; i >= 0; i--)
	{
		printf("%d", arr[i]);
	}
}