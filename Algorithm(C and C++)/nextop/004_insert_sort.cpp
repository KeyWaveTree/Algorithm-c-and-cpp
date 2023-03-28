#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int A[10], n;
#define SWAP(a,b,t) ((t=a),(a=b),(b=t))
void input() {
	int i;
	scanf("%d", &n);//nÀº °¹¼ö
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
}
void run() {
	int temp, i, j;
	A[0] = -987654321;

	for (i = 2; i <= n; i++) {
		temp = A[i];
		for (j = i - 1; 1; j--) {
			if (A[j] > temp) {
				A[j + 1] = A[j];
			}
			else {
				A[j + 1] = temp;
				break;
			}
		}
	}
}
void print() {
	int i;
	for (i = 1; i <= n; i++) {
		printf("%d ", A[i]);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	input();
	run();
	print();
	return 0;
}