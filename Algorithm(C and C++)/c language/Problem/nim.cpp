#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int com;
	int p;
	int s = 12;
	srand(time(NULL));

	printf("12\n");
	while (1)
	{
		printf("스틱 몇개?\n");
		scanf("%d", &p); //scanf("") 문장 쓰면? - 안됨
		if (p > 3)
		{
			printf("다시입력\n");
			continue;
		}
		com = rand() % 4;
		printf("컴 %d개\n", com);
		

		s -= p; 
		if (s < 1) {
			printf("p짐\n");
			break;
		}
		
		s -= com;
		if (s < 1)
		{
			printf("이김\n");
			break;
		}
		printf("스틱 %d\n", s);
	}
}