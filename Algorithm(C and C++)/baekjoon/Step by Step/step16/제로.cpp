#include<iostream>

using namespace std;

int stack[100001];
int top = 0;
int main()
{

	freopen("input.txt", "r", stdin);
	int i;
	int n;
	int value;
	unsigned int sum = 0;

	//stack�� �̿�
	//������ "0"�� ��쿡 ���� �� �ִ� ���� ������ ������ �� �ִ�. - ����÷ο� ���Ͼ

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &value);
		if (value == 0)
		{
			stack[top] = 0;
			top--;
		}
		else
		{
			top++;
			stack[top] = value;
		}
	}

	//stack�� �ִ� ���� �� ����
	for (i = 1; i <= top; i++)
	{
		sum += stack[i];
	}


	printf("%d", sum);

	return 0;
}