//���ִ� ����ó�� stack�� �̿���

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
////	int num; //�ӽ� ����� ��
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
////���� ���̻罽�� ���� ������ �������� 
//// �� ���� �� �ϳ��� �����ϸ� i�� j���� ���̻罽���� ������ �ִٰ� �Ѵ�. 
//
////���� 1: x1 < x3 �̰� x2 > x4
////���� 2: x1 = x3 �̰� x2 > x4
////���� 3: x1 < x3 �̰� x2 = x4
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
//	//�Է�
//	cin >> n;
//	for (i = 0; i < n; i++)
//	{
//		//point, ����, ������
//		cin >> p >> a >> b;
//		//cycle[p].num = p; //�ӽ÷� Ȯ���ϱ� ���ؼ� ����� ���� 
//		cycle[p].x1 = a;
//		cycle[p].x2 = b;
//	}
//
//	//����
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
//		//�Ȱ��� ���� �̹� �����Ѵٸ� 
//		
//		
//		//���� ���� ���� �ʴ´ٸ� lower_bound ���� 
//		//LDS ���� 
//		auto bound_point = lower_bound(lis.begin(), lis.end(), cycle[i], 
//			[](const point& a, const point& b) { return a.x2 >= b.x2; });
//
//		//���� bound_point�� ���� �ִٸ� �ϴ� �ִ´�. 
//		if (bound_point == lis.end())lis.push_back(cycle[i]);
//		//���� lower_bound�� ���� �Ȱ��� ���� ���´ٸ� 
//		else if (bound_point->x1 == cycle[i].x1 && bound_point->x2 == cycle[i].x2) continue;
//		//��ġ�� ã�Ҵٸ� �����Ѵ�. 
//		else *bound_point = cycle[i];
//	}
//
//	cout << lis.size();
//
//	return 0;
//}