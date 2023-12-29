#include<iostream>
#include<algorithm>

using namespace std;

typedef struct table
{
	int real_num;
	int color;
	int size;
	int ans; //�������� ������ �� 
};

table arr[200001];
int check[200001];
int color[200001];

bool compare(const table& a, const table& b)
{	
	return a.size < b.size;
}

bool reset(const table& a, const table& b)
{
	return a.real_num < b.real_num;
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	int j = 0;
	int all_sum = 0;
	int color_cnt = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &arr[i].color, &arr[i].size);
		arr[i].real_num = i;
		color[color_cnt++] = arr[i].color; //�÷� ����
	}

	sort(arr + 1, arr + n + 1, compare);

	for (int i = 1; i <= n; i++)
	{
		//���� ���� �ɷ��ֱ� ���� �ۼ��� 
		//�����̶� �ڿ� �ִ� ���� ��� x
		while (arr[j].size < arr[i].size)
		{
			all_sum += arr[j].size;
			check[arr[j].color] += arr[j].size;
			j++;
		}
		arr[i].ans = all_sum - check[arr[i].color];
	}

	sort(arr + 1, arr + n + 1, reset);

	for (int i = 1; i <= n; i++)
	{
		printf("%d\n",arr[i].ans);
	}

	return 0;
}