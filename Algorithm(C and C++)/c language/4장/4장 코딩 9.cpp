#include<stdio.h>
int main()
{
	//bit 연산해서 LSB(Least Significant Bit) 
	freopen("c.txt", "r", stdin);

	int num;

	scanf("%d", &num);

	printf("%d", num & 1);

}