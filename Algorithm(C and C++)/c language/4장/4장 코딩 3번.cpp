#include<stdio.h>
int main() 
{
	freopen("c.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int prize;
	float so;

	scanf("%d %f", &prize, &so);
	printf("할인 가격 %.2f",  prize-(prize*so/100));
}