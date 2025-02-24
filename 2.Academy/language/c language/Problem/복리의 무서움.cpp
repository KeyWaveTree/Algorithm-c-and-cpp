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
	//콘솔창 제한 때문에 제대로 출력이 안된다. 
}