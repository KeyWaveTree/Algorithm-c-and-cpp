#include<stdio.h>
#include<iostream>

using namespace std;

#define PI 3.14

int main()
{
	freopen("iseq_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	float r;
	float two_pir, pirpir;

	scanf("%f", &r);

	two_pir = 2 * PI * r;
	pirpir = r * r * PI;

	printf("%.2f %.2f", two_pir, pirpir);

	return 0;
}