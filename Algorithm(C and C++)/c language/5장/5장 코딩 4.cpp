#include<stdio.h>
#include<string>
int main()
{
	char ch=' ';

	scanf("%c", &ch);

	if (ch >= 'A' && ch <= 'z') printf("���ĺ�");
	else if (ch >= '0' && ch <= '9') printf("����");
	else printf("Ư������");
}