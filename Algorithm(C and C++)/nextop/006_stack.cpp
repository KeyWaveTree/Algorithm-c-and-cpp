#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a,b,t) ((t=a),(a=b),(b=t))
int A[20], n = 10, check[20] = { 0 }, top;

void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
}
void overflow() {
	printf("넘치네요");
	return;
}
void underflow() {
	printf("모자라요");
	return;
}
void push(int item) {
	if (top == n) {
		overflow();
		return;
	}
	top += 1;
	A[top] = item;

}

int pop() {
	int item;
	if (top == 0) {
		underflow();
		return -1;
	}
	item = A[top];
	top -= 1;
	return item;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	push(3);
	push(10);
	push(20);
	test = pop();
	test = pop();
	return 0;
}