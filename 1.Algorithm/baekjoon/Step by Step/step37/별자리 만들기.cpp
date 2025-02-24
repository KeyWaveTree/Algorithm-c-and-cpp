#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef struct star_point
{
	double x;
	double y;
};

typedef struct line
{
	star_point a;
	star_point b;
	int x_point;
	int y_point;
	double value;
};

line arr[10001];
star_point point[101];
int u[101];

int union_find(int n)
{
	if (n == u[n]) return n;
	return u[n] = union_find(u[n]);
}

bool compare(const line& a, const line& b)
{
	return a.value < b.value;
}

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	scanf("%d", &n);

	//point�� ��� 
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf %lf", &point[i].x, &point[i].y);
	}

	//��� ��带 �̾����� ��
	int count = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			arr[count].a = point[i];
			arr[count].b = point[j];
			arr[count].x_point = i;
			arr[count].y_point = j;
			//����ġ ���
			arr[count].value = sqrt(pow(point[j].x - point[i].x, 2) +
				pow(point[j].y - point[i].y, 2));
			count++;
		}
	}

	//�ּ� ����� Ʈ�� - ũ�罺�� 
	sort(arr + 1, arr + count, compare);

	//���Ͽ� ���ε� �⺻ ���� - �⺻ ������ �ڽ� 
	for (int i = 1; i <=n; i++)
	{
		u[i] = i;
	}

	int temp1 = 0;
	int temp2 = 0;
	double value = 0;
	int cnt = 0;

	for (int i = 1; i <count; i++)
	{
		//temp���� �ε��� üũ 
		temp1 = union_find(arr[i].x_point);
		temp2 = union_find(arr[i].y_point);

		if (temp1 != temp2)
		{
			if (temp1 > temp2) u[temp1] = temp2;
			else if (temp1 < temp2) u[temp2] = temp1;
			value += arr[i].value;
			cnt++;
		}
		if (n - 1 == cnt) break;
	}

	printf("%.2f", value);

	return 0;
}