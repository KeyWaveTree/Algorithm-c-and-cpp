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
		printf("하나를 선택 (0-가위, 1-바위, 2-보)");
		scanf("%d", &chose);
		if (chose > 2) return 0;
		com = rand() % 3;
		printf("사용자 %d\n", chose);
		printf("컴퓨터 %d\n", com);

		if ((chose + 1) % 3 == com) printf("컴퓨터 승");
		else if (chose == com) printf("비겼다.");
		else printf("이겼다.");
	}

	return 0;
}