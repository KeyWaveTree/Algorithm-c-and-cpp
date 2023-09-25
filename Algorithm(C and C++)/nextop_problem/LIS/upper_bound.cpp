#include<iostream>

using namespace std;

int arr[1000];
int size_arr;
int k;

// ���� �� ��������
//upper bound - ����Ž���� �ϸ鼭 ���� Ž���� ������ �� ū ���� ó�� ��ġ 
int upper_bound(int s, int e)//start, end, find_value
{
	int m;
	while (s - e != 0)//����Ž���� �ϸ鼭 ����Ű�� ���� ��ġ�� ���ƾ� �ϱ⿡ 
	{
		m = (s + e) / 2; //ù��° ��ġ�� ������ ��ġ�� ���ϸ� �迭�� ������
		if (arr[m] <= k) s = m + 1; //�������� �Ѱ��־�� �Ѵ�. - �� �ڵ尡 ã�°��� k���� �ƴ� k ������ ū ���̴�.
		else e = m;
	}
	return e;
}

int main() 
{
	scanf("%d", &size_arr);
	for (int i = 1; i <= size_arr; i++)
	{
		scanf("%d", &arr[i]);
	}
	scanf("%d", &k);


}