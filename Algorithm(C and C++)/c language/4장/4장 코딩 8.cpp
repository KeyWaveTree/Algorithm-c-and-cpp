#include<stdio.h>

int main()
{
	//freopen("c.txt", "r", stdin);

	int a, b,c;
	// ������ ������ �����÷ο� ����.  why? - float ũ�Ⱑ int���� ũ�⿡
	// ���� �ڸ��� �������� 1�� �ڸ��� �ޱ�
	
	scanf("%1d%1d%1d", &a, &b,&c);

	printf("%d", a+b+c);
}