#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	//srand(time(null))없으면 프로그램을 다시 실행을 해도 rand()가 넣은 값은 고정된다.
	//int coin = rand() % 2;
	srand(time(NULL));

	int coin = rand() % 2;
	if (coin == 0)printf("뒷면");
	else printf("앞면");

	return 0;
}