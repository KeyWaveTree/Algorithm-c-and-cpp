#include<stdio.h>

int main()
{
	char a, b, c;
	scanf("%c %c %c", &a, &b, &c);

	//10����
	printf("%d %d %d\n", a, b, c);
	//8����
	printf("%o %o %o\n", a, b, c);
	//16����
	printf("%x %x %x\n", a, b, c);

	return 0;
}