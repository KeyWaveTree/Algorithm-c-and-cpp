#include<iostream>

using namespace std;

int main()
{
	int max_point[100] = { 0 };
	int sum = 0;
	int max=-1;
	int max_index = -1;
	int in;
	int i;

	for (i = 0; i < 10; i++)
	{
		cin >> in; 
		sum += in;//����� ���ϱ� ���� ��
		//�ֺ��� ���ϱ� ���� ���̺� ����
		//���� �׻� 10�� ����̱⿡ /10���ϸ� ������ ũ�⸦ �ٿ���
		max_point[in/10]++;
	}

	for (i = 1; i < 100	; i++)
	{
		//�ֺ� ã��
		if (max < max_point[i])
		{
			//�ֺ� ����Ʈ max�� ����
			max = max_point[i];
			//���� �ֺ� �ε����� max_index�� ����
			max_index = i;
		}
	}

	printf("%d\n%d", sum / 10, max_index * 10);
	return 0;
}