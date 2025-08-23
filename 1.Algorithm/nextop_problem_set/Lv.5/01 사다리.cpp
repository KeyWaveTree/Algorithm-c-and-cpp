#include<iostream>

using namespace std;

typedef struct layer
{
	int len;
	int arrow;
};

//�ִ� ���� 3000�� 
layer stick[3000];

int main()
{

	//�ݺ� ���� 
	int i;

	//�ʺ� ���� 
	int width, height;

	//���� �Ÿ� 
	int empty_len;
	//�ִ� ������ ���̸� �����ϴ� ���� 
	int max_len = 0;

	//�Է�
	cin >> height >> width;

	for (i = 0; i < height; i++)
	{
		cin >> stick[i].len >> stick[i].arrow;
	}
	
	//������ ������ �н� 
	for (i = 0; i < height - 1; i++)
	{	
		//���� �����̸� Ȥ�� ���� �Ÿ��� 0�̸� pass
		if (stick[i].arrow == stick[i+1].arrow ||
			width - stick[i].len + stick[i+1].len == 0) continue;

		empty_len = (width - stick[i].len + stick[i + 1].len) / 2;

		if (empty_len > max_len) max_len = empty_len;
	}

	cout << max_len;

	return 0;
}