#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int num;
	int cnt = 0;
	int n = rand() % 100 + 1;
	
	do
	{
		scanf("%d", &num);
		if (num > n) printf("���ڰ� Ů�ϴ�.\n");
		else if (num < n) printf("���ڰ� �۽��ϴ�.\n");
		cnt++;
	} while (n != num);
	printf("����. %d", cnt);

	return 0;
}