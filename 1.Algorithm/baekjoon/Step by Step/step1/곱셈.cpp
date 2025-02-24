#include<stdio.h>
int main()
{
	int a;
	int o, t, th;

	scanf("%d\n", &a);
	scanf("%1d %1d %1d", &o, &t, &th);

	printf("%d\n", a * th);
	printf("%d\n", a * t);
	printf("%d\n", a * o);
	th *= a;
	t *= a * 10;
	o *= a * 100;

	printf("%d\n", th + t + o);
}