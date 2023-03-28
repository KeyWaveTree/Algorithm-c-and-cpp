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
		if (num > n) printf("숫자가 큽니다.\n");
		else if (num < n) printf("숫자가 작습니다.\n");
		cnt++;
	} while (n != num);
	printf("축하. %d", cnt);

	return 0;
}