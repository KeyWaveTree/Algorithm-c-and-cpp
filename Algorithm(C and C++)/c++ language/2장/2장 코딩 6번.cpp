#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n); //5
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%2d",j);
		}
		for (int j = i; j < n; j++) {
			printf(" *");
		}
		
		printf("\n");
	}


	return 0;
}