#include<stdio.h>
int main()
{

	char ch;
	scanf("%c", &ch);

	if (ch >= 'a' && ch <= 'z') printf("소문자");
	else if (ch >= 'A' && ch <= 'Z') printf("대문자");

	return 0;
}