#include<iostream>

using namespace std;

//dfs문제
int map[101][101] = { 0 };//인접 행렬
int check[101] = { 0 };//체크 
int all; //모든 컴퓨터의 수
int con; //연결되어 있는 컴퓨터 수
int s, e;
int cnt;

int input()
{
	int i;
	scanf("%d", &all);
	scanf("%d", &con);

	if (con == 0) return 0;
	//인접행렬 
	for (i = 1; i <= con; i++)
	{
		scanf("%d%d", &s, &e);
		map[s][e] = 1;
		map[e][s] = 1;
	}

	return 1;
}

void dfs(int start)
{
	int i;
	check[start] = 1;
	//연결되어 있는 컴퓨터가 있으면 가자
	//단 갈 수 있으면 
	for (i = 1; i <= all; i++) //현재 i는 end 구간 
	{
		
		if (check[i] == 0 && map[start][i] == 1)
		{
			check[i] = 1;
			cnt++;
			dfs(i);
		}
	}
}

int main() 
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int code = input();
	if (code == 1) dfs(1);
	printf("%d", cnt);
	return 0;
}