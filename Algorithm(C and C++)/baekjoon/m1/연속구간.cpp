#include<iostream>
#include<string>

using namespace std;

int main()
{
	string ebit; //8�� bit�� string���� �����ϸ� �迭�� ���� ������ �ִ�. 
	int max; //���� ���� ���� ���ӵ� �� �ִ���� �����ϴ� ����
	int cnt;//������ ���� �ٸ��� �ʱ�ȭ 
	int i, j;

	for (i = 0; i < 3; i++)
	{
		//�Է¹����� ���� �ʱ�ȭ 
		max = 0, cnt = 1;

		cin >> ebit;
		//8bit�� ebit[7]���� ���� ������ ���� ���߿� �ٸ��� �ʱ�ȭ �� ����
		for (j = 0; j < 8; j++)
		{
			//������ ���� �� ����
			if (ebit[j] == ebit[j + 1]) cnt++;
			//�ٸ��� �ٽ� �ʱ�ȭ 
			else cnt = 1;
			//������ ���� ���� ����� �ִ밪���� ũ�ٸ� ����
			if (max < cnt) max = cnt;
		}
		//�� string ���� �ִ� ���� ���
		printf("%d\n", max);
	}

	return 0;
}