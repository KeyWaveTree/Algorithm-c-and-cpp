#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define N 10

using namespace std;

int arr[N][N];
int r[N][N]; //출력노드
bool cheak[N]; //현재 컴퓨터가 간 노드들 체크 why? 무한반복걸리는 사이클 방지 false 아직 안감, true 갔음
int n=10; // 총 노드 개수

void input()
{

}

void prim()
{
	int i, chk, s, e;
	int min;
	int cnt = 0;// 노드 탐색 개수
	
	while (true)
	{
		min = 1000000000;
		for (chk = 1; chk <= n; chk++) //시작노드 index
		{
			for (i = 1; i <= n; i++) //끝 노드 index
			{
				if (arr[chk][i] != 0 && cheak[chk] == false && min > arr[chk][i])
				{
					min = arr[chk][i]; //가중치 저장
					s = chk; //연결되는 처음의 인덱스
					e = i; //연결되는 끝의 인덱스
				}
			}
		}

		//cheak배열에 다녀온 노드 표기
		cheak[e] = true;

		// 양방향 위치에다가 최소값 넣기
		r[s][e] = min; 
		r[e][s] = min; 

		cnt++; 
		if (cnt == n - 1) break;
	}
}

void print()
{

}


int main()
{
	input();
}