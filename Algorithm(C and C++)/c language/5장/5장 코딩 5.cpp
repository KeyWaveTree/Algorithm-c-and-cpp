#include<stdio.h>
int main()
{

	char ch;
	scanf("%c", &ch);

	if (ch >= 'a' && ch <= 'z') printf("�ҹ���");
	else if (ch >= 'A' && ch <= 'Z') printf("�빮��");

	return 0;
}