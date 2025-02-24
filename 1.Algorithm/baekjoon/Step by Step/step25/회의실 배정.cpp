#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct point
{
	int start;
	int end;
};

vector<point> arr;

bool compare(const point &a, const point &b)
{
	if (a.end == b.end) return a.start < b.start;
	return a.end < b.end;
}

int main()
{
	freopen("input.txt", "r", stdin);

	int n;
	point p;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &p.start, &p.end);
		arr.push_back(p);
	}

	sort(arr.begin(), arr.end(), compare);

	int k=0; //끝나는 강의 index 겹치는 강의가 없어야 함
	int cnt = 1; //하루동안 최대 수용가능한 강의 개수 

	//수업시작하자마자 끝나는 강의가 있으므로 그 반례도 처리해야 함
	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i].start >= arr[k].end)
		{
			cnt++;
			k = i;
		}
	}

	printf("%d", cnt);

	return 0;
}