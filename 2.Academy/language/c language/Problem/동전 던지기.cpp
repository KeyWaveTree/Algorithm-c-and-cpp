#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	//srand(time(null))������ ���α׷��� �ٽ� ������ �ص� rand()�� ���� ���� �����ȴ�.
	//int coin = rand() % 2;
	srand(time(NULL));

	int coin = rand() % 2;
	if (coin == 0)printf("�޸�");
	else printf("�ո�");

	return 0;
}