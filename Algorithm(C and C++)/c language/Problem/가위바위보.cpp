#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	int chose;
	int com;
	while (1)
	{
		printf("�ϳ��� ���� (0-����, 1-����, 2-��)");
		scanf("%d", &chose);
		if (chose > 2) return 0;
		com = rand() % 3;
		printf("����� %d\n", chose);
		printf("��ǻ�� %d\n", com);

		if ((chose + 1) % 3 == com) printf("��ǻ�� ��");
		else if (chose == com) printf("����.");
		else printf("�̰��.");
	}

	return 0;
}