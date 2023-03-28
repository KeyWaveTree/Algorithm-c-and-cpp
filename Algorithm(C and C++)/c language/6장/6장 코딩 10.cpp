#include<stdio.h>

int main()
{
	for (float a = 0; a < 100; a += 10)
	{
		printf("%f %f\n", a, (a - 32) * 5.0 / 9.0);
	}
}