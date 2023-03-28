//6
//5 3 8 1 2 7

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
	int i, f, j, temp;
	for (i = 1; i <= n - 1; i++) {
		f = i;
		for (j = f + 1; j <= n; j += 1) {
			if (A[f] > A[j])f = j;
		}
		SWAP(A[f], A[i], temp);

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