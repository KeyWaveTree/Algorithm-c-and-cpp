#include<iostream>

using namespace std;

int stack[10001];
int check[10001];

int main()
{
	freopen("nextop-problem", "r", stdin);
	
	int n; //�ִ� ����
	int max = 0;//���� ���� ���� ū�� ������ �Ǵ��Ҷ�
	int top, chk;

	cin >> n;
	for (top = 1; top <= n; top++)
	{
		cin >> stack[top];
	}
	
	for (top = 1; top <= n; top++)
	{
		if (stack[top] > max)
		{
			max = stack[top];//���� ���� ���� 
			check[max] = 1;
		}
		else
		{
			if (stack[top] + 1 == stack[top - 1]) check[top] = 1; //���� ���� �����ִ� ���ϰ� 1���� �ۿ� �ȳ���
			else
			{
				for (chk = stack[top - 1] - 1; chk >= stack[top] + 1; chk--)
				{
					if (check[chk] != 1)
					{
						cout << "no"<<'\n';
						return 0;
					}
				}
				check[top] = 1;
			}
		}
	}

	cout << "yes"<<'\n';
	return 0;
}