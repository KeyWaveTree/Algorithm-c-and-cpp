#include<stdio.h>
#include<math.h>

void quad_eqn(int a, int b, int c)
{
	double d, x1, x2;

	//분모 루트 안 값
	d = b * b - 4.0 * a * c; //int 값 주의

	if (d == 0)
	{
		printf("\n");
	}
	else if (d > 0)
	{
		x1 = (-b + sqrt(d)) / (2.0 * a);
		x2 = (-b - sqrt(d)) / (2.0 * a);
		printf("첫번째 %f\n", x1);
		printf("두번째 %f\n", x2);
	}
	else printf("허수근 입니다.\n");
	return;
}

int main()
{
	int a, b, c; 
	scanf("%d %d %d", &a, &b, &c);

	quad_eqn(a, b, c);

}