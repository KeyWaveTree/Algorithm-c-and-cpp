//공주님 정원처럼 stack을 이용함

#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);


}


//#include<iostream>
//#include<algorithm>
//#include<vector>
//
//using namespace std;
//
//typedef struct point
//{
////	int num; //임시 디버깅 용
//	int x1;
//	int x2;
//
//	bool  operator== (const point& p) const
//	{
//		return (p.x1 == x1 && p.x2 == x2);
//	}
//};
//
//point cycle[500001];
//vector<point> lis;
//
////먼저 먹이사슬의 조건 순으로 정렬하자 
//// 세 조건 중 하나를 만족하면 i가 j보다 먹이사슬에서 상위에 있다고 한다. 
//
////조건 1: x1 < x3 이고 x2 > x4
////조건 2: x1 = x3 이고 x2 > x4
////조건 3: x1 < x3 이고 x2 = x4
//
//bool compare(const point& a, const point& b)
//{
//	if (a.x1 == b.x1)return a.x2 > b.x2;
//	else return a.x1 < b.x1;
//}
//
//int n;
//int main()
//{
//	//
//	freopen("input.txt", "r", stdin);
//	int i;
//	int p, a, b;
//	
//	//입력
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		//point, 왼쪽, 오른쪽
//		cin >> p >> a >> b;
//		//cycle[p].num = p; //임시로 확인하기 위해서 사용한 변수 
//		cycle[p].x1 = a;
//		cycle[p].x2 = b;
//	}
//
//	//정렬
//	sort(cycle + 1, cycle + n+1, compare);
//
//	//LDS
//	for (i = 1; i <= n; i++)
//	{
//
//		if (lis.empty())
//		{
//			lis.push_back(cycle[i]);
//			continue;
//		}
//
//		//똑같은 값이 이미 존재한다면 
//		
//		
//		//만약 존재 하지 않는다면 lower_bound 진행 
//		//LDS 실행 
//		auto bound_point = lower_bound(lis.begin(), lis.end(), cycle[i], 
//			[](const point& a, const point& b) { return a.x2 >= b.x2; });
//
//		//만약 bound_point가 끝에 있다면 일단 넣는다. 
//		if (bound_point == lis.end())lis.push_back(cycle[i]);
//		//만약 lower_bound한 값과 똑같은 값이 나온다면 
//		else if (bound_point->x1 == cycle[i].x1 && bound_point->x2 == cycle[i].x2) continue;
//		//위치를 찾았다면 삽입한다. 
//		else *bound_point = cycle[i];
//	}
//
//	cout << lis.size();
//
//	return 0;
//}