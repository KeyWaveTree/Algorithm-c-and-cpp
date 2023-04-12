#define _CRT_SECURE_NO_WARNIGNS
#include<iostream>
#include<stdio.h>

int S[20], A[20], n, top=0;

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
}

void overflow()
{
	printf("overflow");
}


void underflow()
{
	printf("underflow");
}

void push(int &arr)
{
	top++;
	A[top] = arr;
}

int pop()
{
	top--;
	int arr = A[top];
	return arr;
}

void run() {
	int i;
	S[0] = 987654321;
	for (i = 1; i <= n; i++) {
		if (S[top] > A[i])push(A[i]);
		else {
			while (1) {
				if (S[top] > A[i]) {
					push(A[i]);
					break;
				}
				pop();
			}
		}


	}
}

int main()
{

}