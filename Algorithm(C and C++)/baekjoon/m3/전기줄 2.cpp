#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

typedef struct point
{
	int aPoint;
	int bPoint;
	bool  operator== (const point& p) const
	{
		return (p.aPoint == aPoint);
	}
	bool  operator< (const point& p) const
	{
		return (p.bPoint < bPoint && p.aPoint < aPoint);
	}
};

point line[500001];
int check[500001];
vector<point> lis;
map<int, int> back;

int main()
{
	freopen("input.txt", "r", stdin);
	int i;//반복 변수 
	int n;//전기줄 개수 
	int max = 0; //최대 전기줄 번호 
	
	point empty;//a 포인트, b 포인트 

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &empty.aPoint, &empty.bPoint);
		line[empty.aPoint] = empty; //위치에 전기줄을 배치한다.
		if (max < empty.aPoint) max = empty.aPoint;
	}
	
	//LIS
	//1. i위치가 point가 존재한 값이고 lis가 비어있을때 현재 point값을 넣어준다.그다음 continue
	//2. i위치가 point가 존재한 값이고 lis에서 lower bound로 이진탐색을 한다. 이진 탐색위치 +1이 비어있다면 삽입한다.
	//3. 2번에서 이진탐색 위치 +1이 이미 존재한다면 탐색위치를 갱신한다.
	for (i = 0; i <= max; i++)
	{
		
		//line에 i 위치가 비어있다면 continue
		if (line[i].aPoint == 0) continue;

		back[line[i].aPoint] = 0;
		if (lis.empty())
		{ 
			lis.push_back(line[i]); 
			continue;
		}
		// lowerbound가 반환하는 index
		//lowerbound할때 찾는 값은 타입에 맞는 형식으로 써야함 구조체라면 구조체 형식으로 
		auto bound_index = lower_bound(lis.begin(), lis.end(), line[i], [](const point& a, const point& b) {return a.bPoint < b.bPoint; });
		//인덱스를 찾을려면 auto bound_index = lower_bound(lis.begin(), lis.end(), line[i].bPoint)- lis.begin();
		
		if (bound_index != lis.begin()) back[line[i].aPoint] = (bound_index - 1)->aPoint;
		if (bound_index == lis.end()) lis.push_back(line[i]);
		else *bound_index = line[i];

		
	}
	// 전체 사이즈 - lis의 크기 
	cout << n - lis.size()<<'\n';
	//역추적 하기 
	int map_value = lis[lis.size()-1].aPoint;
	check[map_value] = 1;
	for (i = lis.size() - 1; i >= 0; i--)
	{
		if (map_value != lis[i].aPoint)back[lis[i].aPoint] =0;

			if (back.at(map_value) == 0)
			{
				back[map_value] = map_value;
				check[back[map_value]] = 1;
			}
			else
			{
				map_value = back[map_value];
				check[map_value] = 1;
			}
	}

	for (auto& map_key : back)
	{
		if (check[map_key.first]==0 || map_key.second==0) cout << map_key.first << '\n';
	}


	return 0;
}