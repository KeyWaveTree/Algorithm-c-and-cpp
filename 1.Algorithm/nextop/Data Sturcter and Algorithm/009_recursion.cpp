#define _CRT_SECURE_NO_WARNINGS	
#include<iostream>
#include<stdio.h>

using namespace std;

void q1(int a) {
	if (a >= 50)return;
	printf("들어가기 전 a : %d n", a);
	q1(a + 1);
	printf("나와서 a : %d n", a);
}

int main() {
	int x;
	q1(1);
	return 0;
}