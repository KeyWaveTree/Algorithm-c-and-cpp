#include<iostream>
#include<algorithm>

using namespace std;


typedef struct map
{
	int s;
	int e;
	int v;
};

map arr[100001];
int u[10001];
int value;

//start, end, weght


int union_find(int my)
{
	if (u[my] == my) return my;
	//���� �ٲٱ�
	return u[my] = union_find(u[my]);
}

bool compare(const map& a, const map& b)
{
	return a.v < b.v;
}

int main()
{
	//ũ�罺�÷� 

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i;
	int v, e; //���, ����
	int start, end, w;//start, end, weght
	int cnt = 0; //��� ���� Ȯ��

	cin >> v >> e;

	for (i = 1; i <= e; i++)
	{
		cin >> start >> end >> w;
		arr[i].s = start;
		arr[i].e = end;
		arr[i].v = w;
	}

	sort(arr + 1, arr + e + 1, compare);

	//���� union find�� ���ؼ� 
	//�ʹ� ����� �ڽ�
	//����Ŭ Ȯ��
	for (i = 1; i <= v; i++)
	{
		u[i] = i;
	}

	//���� ����� ����
	int temp1;
	int temp2;

	//������ ���� ��ŭ
	for (i = 1; i <= e; i++)
	{
		//���� ����
		temp1 = union_find(arr[i].s);//start
		temp2 = union_find(arr[i].e);//end

		//���������� �ٸ� ��쿡�� ��ȥ�� �� �� �ִ�.
		if (temp1 != temp2)
		{
			u[temp1] = temp2;
			//����ġ ���� Ȥ�� ������� ����
			value += arr[i].v;
			cnt++;


		}
		if (v - 1 == cnt) break;
	}

	cout << value;

	return 0;

}