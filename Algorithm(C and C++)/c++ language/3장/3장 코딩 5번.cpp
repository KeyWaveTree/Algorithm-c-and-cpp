#include<iostream>

using namespace std;

void sayHello(char cnt='1')
{
	for (char i = 0; i < 1; i++)
	{
		cout << "hello ";
	}
}


//����Ʈ �μ��� ����� �� ���� �μ��� ���:�����ε� 
void sayHello(int i, char cnt='1')
{
	for (char i = 0; i < cnt; i++)
	{
		cout << "hello ";
	}
}

int main()
{
	sayHello();
	return 0;
}