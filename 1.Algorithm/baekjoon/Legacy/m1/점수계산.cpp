#include<iostream>

using namespace std;

int main()
{
	int n; //���� ����
	int c; //�� ������ �´��� ���� �ʴ��� ����
	int temp=0; //�����ؼ� ������ ������ ������ ������ �� ���� ����
	int score = 0;// ������ ����

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> c;
		//�Է��� ���� 1�� �´ٸ� 
		if (c)
		{
			//ī��Ʈ ������ temp�� �����ȴ�. 
			temp++;
		}
		else
		{
			//���߿� �Է��� ���� 0�̸� ���ʽ� ������ �ʱ�ȭ ���ش�. 
			temp = 0;
		}
		score += temp;
	}

	printf("%d", score);

	return 0;
}
