#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	//in - ������ ��
	//out - ������ ��
	int in, out;
	int max = 0; //���� �ִ� �ο�
	int sum = 0; //in/ out ������ ���� �°�

	for (int i = 0; i < 10; i++)
	{
		cin >> out;
		cin >> in;

		sum = sum - out + in;
		if (sum > max)max = sum;
	}

	cout << max;
	return 0;
}