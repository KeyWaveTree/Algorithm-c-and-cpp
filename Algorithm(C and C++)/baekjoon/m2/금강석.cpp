#include<iostream>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

point bundle[100];
//너비, 높이, 강석 개수, 대각선 길이 
int n, m, t, k;
int ans;
int max_x, max_y;

//1. 전체 좌표를 45도 기울여서 푼 문제
void plan(int x, int y)
{
	int q;
	int cnt = 0;
	int p = y - x; //좌표 위치에서 벗어난 값

	//좌표값과 k를 더한다. 
	if (x + y + k > 2 * n) {
		x = n - (p / 2) - (k / 2); //벗어난 값을 포함해서 행렬을 다시 교정
		y = n + (p / 2) - (k / 2); //
	}
	//구간에서 각각 -k/2 하여 포인트 지정 
	for (q = 0; q < t; q++)//강석의 개수
	{
		//금강석 맨하탄 거리 - 현재 좌표를 회전했으므로 필요 없음
		//if (abs(bundle[q].x - x) + abs(bundle[q].y - y) <= k / 2) cnt++;
		if (x <= bundle[q].x && bundle[q].x <= x + k && y<= bundle[q].y && bundle[q].y <= y+k) cnt++;
	}
	
	if (ans < cnt)
	{
		//정사각형 생성이 되는 것은 아래에서 부터 위로 생성
		//왼쪽 아래 점에서 부터 대각선 길이 더하기 - 중점
		max_x = x + k/2; 
		max_y = y + k/2;
		ans = cnt;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int i, j;
	int w, h;
	int x, y;
	scanf("%d%d%d%d", &n, &m, &t, &k);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &x, &y);
		//회전 행렬 
		bundle[i].x = x+y;
		bundle[i].y = x-y;
	}

	//플레인 스위핑
	for (i = 0; i < t; i++)//가로 
	{	
		for (j = 0; j < t; j++)//세로
		{
			//자동적으로 겹치는 구간에 배치가 됨
			//레이저 대각선으로 변형 - 회전 행렬
			w = bundle[i].x;
			h = bundle[j].y;
			//좌표가 격자 가운데에 있다면 
			if ((w + h) % 2)
			{
				//주위 4가지 방향으로 다 탐색 - 가장 최대 금강석 수 	
				plan(w - 1, h);
				plan(w, h - 1);
				plan(w + 1, h);
				plan(w, h + 1);
			}
			//그 이외 
			else plan(w, h);
		}
	}

	//만약 포인트가 공간안에 없다면 다시 재배치 

	//회전 행렬 -> 다시 원상 복구 /2 짝수 좌표를 위해서 
	printf("%d %d\n%d", (x+y)/2, (x-y)/2, ans);

	return 0;
}