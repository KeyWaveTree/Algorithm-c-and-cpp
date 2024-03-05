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
	int i;//�ݺ� ���� 
	int n;//������ ���� 
	int max = 0; //�ִ� ������ ��ȣ 
	
	point empty;//a ����Ʈ, b ����Ʈ 

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &empty.aPoint, &empty.bPoint);
		line[empty.aPoint] = empty; //��ġ�� �������� ��ġ�Ѵ�.
		if (max < empty.aPoint) max = empty.aPoint;
	}
	
	//LIS
	//1. i��ġ�� point�� ������ ���̰� lis�� ��������� ���� point���� �־��ش�.�״��� continue
	//2. i��ġ�� point�� ������ ���̰� lis���� lower bound�� ����Ž���� �Ѵ�. ���� Ž����ġ +1�� ����ִٸ� �����Ѵ�.
	//3. 2������ ����Ž�� ��ġ +1�� �̹� �����Ѵٸ� Ž����ġ�� �����Ѵ�.
	for (i = 0; i <= max; i++)
	{
		
		//line�� i ��ġ�� ����ִٸ� continue
		if (line[i].aPoint == 0) continue;

		back[line[i].aPoint] = 0;
		if (lis.empty())
		{ 
			lis.push_back(line[i]); 
			continue;
		}
		// lowerbound�� ��ȯ�ϴ� index
		//lowerbound�Ҷ� ã�� ���� Ÿ�Կ� �´� �������� ����� ����ü��� ����ü �������� 
		auto bound_index = lower_bound(lis.begin(), lis.end(), line[i], [](const point& a, const point& b) {return a.bPoint < b.bPoint; });
		//�ε����� ã������ auto bound_index = lower_bound(lis.begin(), lis.end(), line[i].bPoint)- lis.begin();
		
		if (bound_index != lis.begin()) back[line[i].aPoint] = (bound_index - 1)->aPoint;
		if (bound_index == lis.end()) lis.push_back(line[i]);
		else *bound_index = line[i];

		
	}
	// ��ü ������ - lis�� ũ�� 
	cout << n - lis.size()<<'\n';
	//������ �ϱ� 
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