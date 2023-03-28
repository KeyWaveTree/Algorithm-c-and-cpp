#define _CRT_SECURE_NO_WARNINGS
#define SWAP(a,b,t) ((t=a),(a=b),(b=t))
#include <stdio.h>
int A[10], n;


void print() {
	int i;
	for (i = 1; i <= n; i++) {
		printf("%3d", A[i]);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int j, i, temp, h, k;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}
	h = 3; //임의의 수
	A[0] = -9876543321;
	while (1) {
		for (k = 1; k <= h; k++) {
			for (i = k; i <= n; i = i + h) {
				temp = A[i];
				for (j = i - h; ; j = j - h) {
					if (A[j] > temp) {
						A[j + h] = A[j];
					}
					else if (j < 1 || A[j] < temp) {
						A[j + h] = temp;
						break;
					}
				}
			}
		}
		if (h == 1)break;
		h = h / 2;
	}
	print();


	return 0;
}