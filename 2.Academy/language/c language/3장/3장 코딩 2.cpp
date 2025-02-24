// 실수로 입력 다항식 값을 계산하는 프로그램

#include<stdio.h>

int main()
{
	float x;
	float answer;
	scanf("%f", &x);

	answer = 3 * (x * x * x) - 7 * (x * x) + 9;

	printf("%f", answer);
}