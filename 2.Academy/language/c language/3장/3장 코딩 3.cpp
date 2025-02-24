#include<stdio.h>

#define P 3.3058

int main()
{
	float m;
	scanf("%f", &m);

	printf("%f제곱 미터는 %f 평이다.", m, m /P); 
	// 왜 평수를 제곱미터 나누기 p인가 - 평을 제곱 미터로 계산할때 곱하기를 했으니까 반대로 나누기를 하면 된다. 

}