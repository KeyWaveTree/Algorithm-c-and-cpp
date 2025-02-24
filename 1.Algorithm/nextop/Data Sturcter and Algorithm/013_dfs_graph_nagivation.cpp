#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<iostream>
#define N 10

using namespace std;

int n, A[N][N], check[N], answer[N];

void input() {
	int i, j;
	scanf("%d", &n); //노드는n 간선은k
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
		}
	}
}

void print()
{
	for (int i = 1; i <= n; i++)
	{
		printf("%3d", answer[i]);
	}
	cout << endl;
}


//start
void Q(int s, int v)
{
		int e;
		check[s] = 1; // 시작위치에 1 지정
		answer[v] = s;
		if (v == n) {
			print();
			check[s] = 0; //이걸 안하면 1개밖에 출력안함 (why? - 돌아 왔을때 같은 곳을 반복하지 않을려고 한 조건이 문제가 발생함)
			return;
		}
		for (e = 1; e <= n; e++) {
			if (A[s][e] == 1 && check[e] == 0)
				Q(e, v+ 1);
		}
		check[s] = 0;
}


int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	input();
	for(int i=1;i<=n;i++)Q(i, 1);
	print();
}