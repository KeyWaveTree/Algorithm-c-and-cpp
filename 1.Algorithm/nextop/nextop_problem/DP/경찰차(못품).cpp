#include<iostream>

using namespace std;

//경찰차의 구조를 만든다. 
typedef struct patrol
{
	int car;
	int x;//동서 방향 
	int y;//남북 방향 
};

patrol incident[1001];//사건 순서 배열 
//맨하탄거리를 이용해서 dfs
//동적 
int main()
{
	freopen("input.txt", "r", stdin);
	
	
	
	int n;
	int w;
	cin >> n >> w;

	//경찰차 1, 2만들기 
	patrol one = { 1, 1, 1 };
	patrol two = { 2, n, n };
}