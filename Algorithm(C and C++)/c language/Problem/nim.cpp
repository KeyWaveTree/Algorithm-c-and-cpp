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
		printf("��ƽ �?\n");
		scanf("%d", &p); //scanf("") ���� ����? - �ȵ�
		if (p > 3)
		{
			printf("�ٽ��Է�\n");
			continue;
		}
		com = rand() % 4;
		printf("�� %d��\n", com);
		

		s -= p; 
		if (s < 1) {
			printf("p��\n");
			break;
		}
		
		s -= com;
		if (s < 1)
		{
			printf("�̱�\n");
			break;
		}
		printf("��ƽ %d\n", s);
	}
}