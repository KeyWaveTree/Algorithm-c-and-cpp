#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	double distanse;
	double time;
	double bun;
	double sec;
	double ans;
	printf("�Ÿ� �Է�\n");
	scanf("%lf", &distanse);
	
	printf("�ð� �Է�\n");
	scanf("%lf", &time);

	printf("�� �Է�\n");
	scanf("%lf", &bun);

	printf("�� �Է�\n");
	scanf("%lf", &sec);

	ans = (distanse / 1000) /( time + (bun / 60) + (sec / 3600));
	printf("�ӵ�: %.6lf", ans);
}