#include<stdio.h>

int main()
{
	int i;//�ݺ��� ���� 
	int n;//�Էº��� 

	int max = 0; //�ִ�ġ�� �� ���� max
	int loca = 0; //�ִ�ġ�� ��ġ ���� 
	for (i = 1; i <= 9; i++) //�Է¹��� Ƚ�� �� ���� 
	{
		scanf("%d", &n);
		//���� ���� �Է��Ѱ��� max������ ũ�ٸ�  
		if (n > max)
		{
			max = n;//�ִ� ����
			loca = i;//�ִ� ��ġ ���� - 
		}
	}

	printf("%d\n%d", max, loca);

	return 0;

}