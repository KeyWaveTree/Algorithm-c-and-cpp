#include<stdio.h>
#include<math.h>

int main()
{
	int x1, y1;
	int x2, y2;
	scanf("%d%d", &x1, &y1);
	scanf("%d%d", &x2, &y2);

	printf("두점 사이 거리 %lf", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));

	return 0;
}