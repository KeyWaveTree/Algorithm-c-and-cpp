//���� ���� ���� ���� 21�����
//��ȣ ���� ����
//��� ���- ��� ��� 
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

//��ū ���� stack
char data_stack[102];
int data_stack_top;

int pop(char stack[]);

int main()
{
	int i = 0;
	int cnt = 0;//��ū �и� �ε���
	char c = 0;

	//�Է�
	char input_data[102] = { '\0' };

	//��ū �и� ������
	char op[500] = { '\0' };
	int data[500] = { 0 };

	//�������� �� ������ 
	char post_op[500] = { '\0' };
	int post_data[500] = { 0 };

	//stack���� ���� ���� ��ū ������ ���� ������ 
	int sum_data = 0;

	//���� ���� ������ 
	char temp = '\0';

	//�Է� ���� 
	cin >> input_data;
	//(c = input_data[i]) != '\0') �� ��쿡�� 
	//���ڵ����Ͱ� stack������ ���� �� �ֱ⿡ �Էµ������� �� ���������� �ǹ̾��� �����ǵ����� ~�� �־��� �����̴�. 
	input_data[strlen(input_data)] = '~';

	//�������� ���ڵ����� �϶� ���� ó�� ������� - �ذ�
	while ((c = input_data[i]) != '\0')
	{
		if (c >= '0' && c <= '9')
		{
			data_stack_top++;
			data_stack[data_stack_top] = c;

			// ���� �����Ͱ� ������ �� �ֱ⿡ 
		}
		//���� �����Ͱ� ���ڿ����� 
		else if ((temp >= '0' && temp <= '9') && (c == '(' || c == ')' || c == '*' || c == '/' || c == '+' || c == '-'))
		{
			sum_data = pop(data_stack);
			data[cnt++] = sum_data;
			op[cnt++] = c;

		}
		//���� �����Ͱ� �����ڿ����� 
		else
		{
			op[cnt++] = c;
		}

		temp = c;
		i++;
	}

	//���� ǥ������� �ٲٱ� 
	//���� �� ��ǰ.


	return 0;
}

int pop(char stack[])
{
	int i = 0;
	int sum = 0;
	while (data_stack_top != 0)
	{
		sum += (stack[data_stack_top] * (int)pow(10, i));
		data_stack_top--;
		i++;
	}

	return sum;
}
