#include<iostream>

using namespace std;

int main()
{
	//A, B�� ī��� �� 10��
	int card[2][10] = { 0 };

	int a_cnt=0; //A�� �̱� ��
	int b_cnt = 0;//B�� �̱� ��
	int i, j;
	int a = 0, b = 1; 
	//a-0��° ĭ ���
	//b-1��° ĭ ���

	//�Է�
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 10; j++)
		{
			cin >> card[i][j];
		}
	}

	//�� �ε��� ���� ���� ��Ҹ� �������� 
	for (i = 0; i < 10; i++)
	{
		//�������� �ѱ� - ��� �� �ʿ���� �̱� Ƚ���� üũ
		if (card[a][i] == card[b][i]) continue;
		else if (card[a][i] > card[b][i]) a_cnt++;
		else if (card[a][i] < card[b][i])b_cnt++;
	}

	if (a_cnt > b_cnt) printf("%c", 'A');
	else if (a_cnt < b_cnt) printf("%c", 'B');
	else printf("%c", 'D');

	return 0;
}