#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define SIZE 10 //������������ ���ϴµ��� ���� �����մϴ�. 


int S[SIZE + 1]; //0���� ĭ�� ����θ� �������� ��������. 
int top;

void overflow()
{
	printf("�ʰ�(�� ����) ����");
	return; //void return�� ��� �����մϴ�.
}

void underflow()
{
	printf("�ٴ�(�� ����) ����");
	return;//void return�� ��� �����մϴ�.
}

void push(int item)
{
	if (top == SIZE)
	{
		overflow();
		return; //push �Լ� ����
	}

	top++;
	S[top] = item;
}

int pop()
{
	int temp = S[top];
	if (top == 0)
	{
		underflow();
		return -1; //pop�Լ� ����
	}

	S[top] = 0;
	top--;

	return temp; //���ִ� ���� �����ֱ� ���� return 
}

int main()
{
	push(10);
	push(20);
	printf("%d\n", pop());//20�� �������� Ȯ��
	printf("%d\n", pop());//10�� �������� Ȯ��
	printf("%d\n", pop()); //����÷ο찡 �����°��� Ȯ��

	return 0;
}