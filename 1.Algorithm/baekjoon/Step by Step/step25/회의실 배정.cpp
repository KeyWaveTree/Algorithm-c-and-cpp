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

	int k=0; //������ ���� index ��ġ�� ���ǰ� ����� ��
	int cnt = 1; //�Ϸ絿�� �ִ� ���밡���� ���� ���� 

	//�����������ڸ��� ������ ���ǰ� �����Ƿ� �� �ݷʵ� ó���ؾ� ��
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