#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(a,b,t) ((t=a),(a=b),(b=t))

int A[20], n, check[20] = { 0 };
void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
}

void run() {
	int i, j;
	for (i = 1; i <= n; i++) {
		if (A[i - 1] < A[i]) {
			check[A[i]] = 1;
		}
		else {
			for (j = A[i - 1] - 1; j > A[i] + 1; j--) {
				//j -> 8, 7
				if (check[j] == 0) {  
					printf("¾ÈµÊ");
					return;
				}
			}
			check[A[i]] = 1;
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	input();
	run();
	return 0;
}