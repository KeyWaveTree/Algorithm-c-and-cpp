#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int A[10], n;
void SWAP(int* aa, int* bb) {
	int temp;
	temp = *aa;
	*aa = *bb;
	*bb = temp;
}

void input() {
	int i;
	scanf("%d", &n);//n은 갯수
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
}
void run() {
	int flag, i, j, temp;
	for (j = 1; j <= n - 1; j++) {
		flag = 0;  /////////////
		for (i = 1; i <= n - j; i++) {
			if (A[i] > A[i + 1]) {
				flag = 1;  /////////////////////
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}
		if (flag == 0) {
			break;
		}  //정렬이 되어있다.

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