#include<stdio.h>

int main()
{
	freopen("c.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int w;
	float inch;
	float bmi = 0;
	
	scanf("%d", &w);
	scanf("%f", &inch);

	bmi = w / (inch * inch);
	printf("BMI´Â %.2f", bmi);
}