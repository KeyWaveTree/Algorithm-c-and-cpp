#include<stdio.h>

int main()
{
	freopen("output.txt", "w", stdout);
	double m = 1.0;

	for (int i = 1; i <= 100; i++)
	{
		m *= 2;
		printf("%d %lf\n", i, m);
	}
	//�ܼ�â ���� ������ ����� ����� �ȵȴ�. 
}