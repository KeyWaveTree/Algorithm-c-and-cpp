#include<iostream>

using namespace std;

int main()
{
	//9*9 ��Ŀ��� �ε��� ���� ���ϰ� ����ϱ� ���� 10*10
	int arr[10][10];
	int i, j;
	int max=-1;//�ִ밪�� 0�̸��̹Ƿ� -1
	int max_i = 0;//�ִ밪�� ������ �ִ� �� ��ġ 
	int max_j = 0;//�ִ밪�� ������ �ִ� �� ��ġ

	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			//�Է�
			cin >> arr[i][j];

			//�Է� ���� ���� �ִ밪�� �� 
			if (max < arr[i][j])
			{
				//��ũ�� �ʿ��� ���� ����
				max = arr[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	printf("%d\n", max);
	printf("%d %d", max_i, max_j);

	return 0;
}