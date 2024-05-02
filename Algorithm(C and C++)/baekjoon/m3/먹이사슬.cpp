#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct cycle
{
	int L;
	int R;

	bool operator ==(cycle& o) {
		return L == o.L && R == o.R;
	}
};

vector<cycle> line;
vector<int> lis(1, -1);
int n;

//먼저 먹이사슬의 조건 순으로 정렬하자 
//세 조건 중 하나를 만족하면 i가 j보다 먹이사슬에서 상위에 있다고 한다. 

//조건 1: x1 < x3 이고 x2 > x4
//조건 2: x1 = x3 이고 x2 > x4
//조건 3: x1 < x3 이고 x2 = x4

//이전 버전
// compare
//만약 왼쪽 좌표끼리 같다면 오른쪽 좌표가 큰 순으로 내림차 순 
//if (a.x1 == b.x1)return a.x2 > b.x2;
//왼쪽 좌표가 같지 않다면 오름차 순 

//
bool compare(const cycle& a, const cycle& b)
{
	//x2 좌표기준으로 정렬을 하자 
	//만약 각 x2좌표가 같은 경우라면 짧은 순서대로 하자
	
	//두 선 중 길이가 긴것을 어떻게 판단하는가? 
	//x1 좌표 수치가 작은 수치일 수록 길이가 길다. 
	if (a.L == b.L) return a.R >= b.R;//앞 x1의 크기가 커야 한다. 
	return a.L < b.L;
	//왜 내림차순
	//크기 가 같다면 왼쪽 좌표가 작은 순으로 오름차 순을 해야 범위가 넓어진다. 
	//크기 순으로 정렬해야 하는가?
}
int main()
{
	freopen("input.txt", "r", stdin);
	//번호, x1, x2
	int from, left, right;
	int i;
	int max = 1;

	//입력부
	cin >> n;//line의 개수 
	line.resize(n);
	
	for (i = 0; i < n; i++)
	{
		cin >> from >> line[i].L >> line[i].R;
	}
	
	//먼저 정렬 
	sort(line.begin(), line.end(), compare);
	// 중복 제거 : 정렬이 되어 있어야 중복 제거가 가능해짐. 
	line.erase(unique(line.begin(), line.end()), line.end());


	//LIS	
	for (i = 0; i < line.size(); i++)
	{
		
		//만약 존재 하지 않는다면 upper_bound 진행 
		//LIS 실행
		//upperbound가 반환하는 index
		//upperbound할때 찾는 값은 타입에 맞는 형식으로 써야함 구조체라면 구조체 형식으로 
		auto bound_point = upper_bound(lis.begin(), lis.end(), line[i].R, 
			// 어떤 기준으로 upperbound를 찾을 것인가? 
			//먹이 사슬 상위 왼쪽
			//조건 1: x1 < x3 이고 x2 > x4
			//조건 2: x1 = x3 이고 x2 > x4
			//조건 3: x1 < x3 이고 x2 = x4
			[](int a, int b) {return a > b; });

		//만약 bound_point가 끝에 있다면 일단 넣는다. 
		if (bound_point == lis.end())lis.push_back(line[i].R);
		//위치를 찾았다면 삽입한다. 
		else *bound_point = line[i].R;
	}

	cout << lis.size();

	//이전 결과 
	//처음 스택 지정값
	//stack[++top] = line[1];
	//for (i = 2; i <= n; i++)
	//{
	//	//line의 i 값과 top에 먹이사슬이 포함 된다면 push
	//	//먹이사슬 포함 여부 

	//	//조건 1: x1 < x3 이고 x2 > x4
	//	//조건 2: x1 = x3 이고 x2 > x4
	//	//조건 3: x1 < x3 이고 x2 = x4
	//	if ((stack[top].x1 < line[i].x1 && stack[top].x2 > line[i].x2)
	//		|| (stack[top].x1 == line[i].x1 && stack[top].x2 > line[i].x2)
	//		|| (stack[top].x1 < line[i].x1 && stack[top].x2 == line[i].x2))
	//	{
	//		stack[++top] = line[i];
	//	}

	//	//그렇지 않을경우 
	//	else
	//	{
	//		//먹이사슬에 만족될거나 top의 위치가 0일때까지 pop연산 
	//		while (!((stack[top].x1 < line[i].x1 && stack[top].x2 > line[i].x2)
	//			|| (stack[top].x1 == line[i].x1 && stack[top].x2 > line[i].x2)
	//			|| (stack[top].x1 < line[i].x1 && stack[top].x1 == line[i].x2)) && top!=0)
	//		{
	//			
	//			top--;
	//		}
	//		//pop연산 이후 삽입
	//		stack[++top] = line[i];
	//	}

	//	if (max < top) max = top;
	//}

	//cout << max;
	return 0;
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