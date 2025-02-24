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
	printf("거리 입력\n");
	scanf("%lf", &distanse);
	
	printf("시간 입력\n");
	scanf("%lf", &time);

	printf("분 입력\n");
	scanf("%lf", &bun);

	printf("초 입력\n");
	scanf("%lf", &sec);

	ans = (distanse / 1000) /( time + (bun / 60) + (sec / 3600));
	printf("속도: %.6lf", ans);
}