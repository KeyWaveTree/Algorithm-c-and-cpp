#define _CRT_SEUCRE_NO_WARNINGS
#include<stdio.h>
#include<iostream>

#define N 10

struct Linked
{
	int v;
	Linked *next;
};

Linked *matrix[N];
//�����Ϳ��� ����ü�� Ŭ���������� � ��Ҹ� ����ų�� ->����(��ġ�� ����Ű�� ���̴� �׷���.)
//�Ϲ� ����ü Ŭ���������� .�� ����.

int main()
{
	for (int i = 0; i < N; i++)
	{
		//������ ���־����� ���� ������ �ȵ�
		matrix[i] = new Linked;
		matrix[i]->v = -1;
		matrix[i]->next = NULL;

	}


	Linked* temp = new Linked;   //�ӽ� temp���� ��������
	temp->v = 10;
	matrix[3]->next = temp;//1.

	temp = new Linked;   //�ӽ� temp���� ��������
	temp->v = 20;
	matrix[2]->next = temp; //1.


	temp = new Linked;   //�ӽ� temp���� ��������
	temp->v = 200;
	temp->next = matrix[3]->next; //2.
	matrix[3]->next = temp;

	temp = new Linked;   //�ӽ� temp���� ��������
	temp->v = 300;
	temp->next = matrix[3];//2.
	matrix[3]->next = temp;

	//1�� 2�� ���̴� �����ΰ�?
	// 
	//temp->next=matrix[u]->next;  //matrix�濡 �Ŵ� ������ temp�� �ϴ� �Ŵܴ�
	//temp->v=v;   //temp �� ���� ���� ����  (������� ���� ����)
	//matrix[u]->next=temp;  //temp�� matrix�� �Ŵܴ�.  ��, �Ŵ� ������ �ȴ�.

	return 0;
}