
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int p(char* ap, char a, char* bp, char b)
{
	printf("%d=%c,%d=%c \n", (int)ap, a, (int)bp, b); return 1;
}

void strcpy_pt2(char* a, char* b)
{
	a = (char*)malloc(100);
	for (; (*a = *b) && p(a, *a, b, *b); a++, b++);

}
void main()
{
	char* a = "ABCDE"; // a 의 주소값은 정수로 100 이라 가정
	char* b = "hong"; // b에 저장된 주소는 정수로 200 이라 가정
	strcpy_pt2(a, b);
}