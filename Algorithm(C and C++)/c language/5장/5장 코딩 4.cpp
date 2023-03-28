#include<stdio.h>
#include<string>
int main()
{
	char ch=' ';

	scanf("%c", &ch);

	if (ch >= 'A' && ch <= 'z') printf("알파벳");
	else if (ch >= '0' && ch <= '9') printf("숫자");
	else printf("특수문자");
}