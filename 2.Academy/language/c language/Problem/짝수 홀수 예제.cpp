#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
	freopen("c.txt", "r", stdin);

	int number;

	scanf("%d", &number);

	if (number % 2 == 0) printf("¦��");
	else printf("Ȧ��");
}