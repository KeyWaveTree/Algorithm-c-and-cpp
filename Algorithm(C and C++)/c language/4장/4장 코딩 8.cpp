#include<stdio.h>

int main()
{
	//freopen("c.txt", "r", stdin);

	int a, b,c;
	// 정수로 받을때 오버플로우 난다.  why? - float 크기가 int보다 크기에
	// 정수 자릿수 제한으로 1의 자리만 받기
	
	scanf("%1d%1d%1d", &a, &b,&c);

	printf("%d", a+b+c);
}