#include<iostream>

using namespace std;

typedef struct point
{
	int x;
	int y;
};

point bundle[101];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	//n-바다 영역, L-그물의 둘레, m - 물고기의 수
	int n, l, m;
	int i, j, k;//반복값
	int w, h;//플레인 스위핑 격자 좌표
	int a, b;//그물의 너비, 높이
	int cnt=0;//물고기 개수 세기
	int max = 0;
	scanf("%d%d%d", &n, &l, &m);
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d", &bundle[i].x, &bundle[i].y);
	}

	//플레인 스위핑
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			//격자 지점
			w = bundle[i].x;
			h = bundle[j].y;
			
			//각 지점안에 있는 최대 물고기는?
			//그전에 그물 조건 
			if (l % 2 != 0) continue;

			//둘레 a:1~l/2, b=l/2~1
			for (a = 1; a < l / 2; a++)
			{
				//물고기 개수 초기화
				cnt = 0;

				b = (l / 2) - a;
				//위치 검색 
				for (k = 1; k <= m; k++)
				{
					if (w <= bundle[k].x && bundle[k].x <= w + a && h <= bundle[k].y && bundle[k].y <= h + b) cnt++;
				}
				if (max < cnt)max = cnt;
			}
		}
	}

	//출력 
	printf("%d", max);
	return 0;
}