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

//���� ���̻罽�� ���� ������ ��������
//�� ���� �� �ϳ��� �����ϸ� i�� j���� ���̻罽���� ������ �ִٰ� �Ѵ�.

//���� 1: x1 < x3 �̰� x2 > x4
//���� 2: x1 = x3 �̰� x2 > x4
//���� 3: x1 < x3 �̰� x2 = x4

//���� ����
// compare
//���� ���� ��ǥ���� ���ٸ� ������ ��ǥ�� ū ������ ������ ��
//if (a.x1 == b.x1)return a.x2 > b.x2;
//���� ��ǥ�� ���� �ʴٸ� ������ ��

//
bool compare(const cycle& a, const cycle& b)
{
    //x2 ��ǥ�������� ������ ����
    //���� �� x2��ǥ�� ���� ����� ª�� ������� ����

    //�� �� �� ���̰� ����� ��� �Ǵ��ϴ°�?
    //x1 ��ǥ ��ġ�� ���� ��ġ�� ���� ���̰� ���.
    if (a.L == b.L) return a.R >= b.R;//�� x1�� ũ�Ⱑ Ŀ�� �Ѵ�.
    return a.L < b.L;
    //�� ��������
    //ũ�� �� ���ٸ� ���� ��ǥ�� ���� ������ ������ ���� �ؾ� ������ �о�����.
    //ũ�� ������ �����ؾ� �ϴ°�?
}
int main()
{
    freopen("input.txt", "r", stdin);
    //��ȣ, x1, x2
    int from, left, right;
    int i;
    int max = 1;

    //�Էº�
    cin >> n;//line�� ����
    line.resize(n);

    for (i = 0; i < n; i++)
    {
        cin >> from >> line[i].L >> line[i].R;
    }

    //���� ����
    sort(line.begin(), line.end(), compare);
    // �ߺ� ���� : ������ �Ǿ� �־�� �ߺ� ���Ű� ��������.
    line.erase(unique(line.begin(), line.end()), line.end());


    //LIS
    for (i = 0; i < line.size(); i++)
    {

        //���� ���� ���� �ʴ´ٸ� upper_bound ����
        //LIS ����
        //upperbound�� ��ȯ�ϴ� index
        //upperbound�Ҷ� ã�� ���� Ÿ�Կ� �´� �������� ����� ����ü��� ����ü ��������
        auto bound_point = upper_bound(lis.begin(), lis.end(), line[i].R,
                // � �������� upperbound�� ã�� ���ΰ�?
                //���� �罽 ���� ����
                //���� 1: x1 < x3 �̰� x2 > x4
                //���� 2: x1 = x3 �̰� x2 > x4
                //���� 3: x1 < x3 �̰� x2 = x4
                                       [](int a, int b) {return a > b; });

        //���� bound_point�� ���� �ִٸ� �ϴ� �ִ´�.
        if (bound_point == lis.end())lis.push_back(line[i].R);
            //��ġ�� ã�Ҵٸ� �����Ѵ�.
        else *bound_point = line[i].R;
    }

    cout << lis.size();

    //���� ���
    //ó�� ���� ������
    //stack[++top] = line[1];
    //for (i = 2; i <= n; i++)
    //{
    //	//line�� i ���� top�� ���̻罽�� ���� �ȴٸ� push
    //	//���̻罽 ���� ����

    //	//���� 1: x1 < x3 �̰� x2 > x4
    //	//���� 2: x1 = x3 �̰� x2 > x4
    //	//���� 3: x1 < x3 �̰� x2 = x4
    //	if ((stack[top].x1 < line[i].x1 && stack[top].x2 > line[i].x2)
    //		|| (stack[top].x1 == line[i].x1 && stack[top].x2 > line[i].x2)
    //		|| (stack[top].x1 < line[i].x1 && stack[top].x2 == line[i].x2))
    //	{
    //		stack[++top] = line[i];
    //	}

    //	//�׷��� �������
    //	else
    //	{
    //		//���̻罽�� �����ɰų� top�� ��ġ�� 0�϶����� pop����
    //		while (!((stack[top].x1 < line[i].x1 && stack[top].x2 > line[i].x2)
    //			|| (stack[top].x1 == line[i].x1 && stack[top].x2 > line[i].x2)
    //			|| (stack[top].x1 < line[i].x1 && stack[top].x1 == line[i].x2)) && top!=0)
    //		{
    //
    //			top--;
    //		}
    //		//pop���� ���� ����
    //		stack[++top] = line[i];
    //	}

    //	if (max < top) max = top;
    //}

    //cout << max;
    return 0;
}


//#include<iostream>
//#include<1.Algorithm>
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