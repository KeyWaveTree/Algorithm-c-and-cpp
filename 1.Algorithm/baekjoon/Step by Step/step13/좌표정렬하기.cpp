#include<iostream>
#include<algorithm>
#include<vector>

#define N 100000

using namespace std;

typedef struct point
{
	int x, y;
};

point p;

bool compereXY(point & p1, point &p2)
{
	if (p1.x < p2.x) return true;
	else if (p1.x == p2.x)
	{
		return p1.y < p2.y;
	}

	return false;
}


int main()
{
	vector<point> v;
	int n;
	int x, y;
	scanf("%d", &n);
	
	for (int i = 0; i <n; i++)
	{
		scanf("%d %d", &x, &y);
		p.x = x;
		p.y = y;
		v.push_back(p);
	}

	sort(v.begin(), v.end(), compereXY);

	for (auto& i : v)
	{
		printf("%d %d\n", i.x, i.y);
	}
		
	return 0;
}