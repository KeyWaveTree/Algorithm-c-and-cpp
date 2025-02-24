#include<iostream>
#include<vector>
#include<set>
#include<cmath>

using namespace std;

vector<long long> tree;
long long check[4097160];

void change(long long locate, long long value);
void seg_sum(long long start, long long end);
long long sub_sum(long long index);

long long seg_index;//ó�� �ε����� �������ش�. 

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(), cout.tie(), ios::sync_with_stdio(false);

	long long i;
	long long n, m, k;
	long long a, b, c;
	//m ���� ������ �Ͼ Ƚ�� 
	//k �� ������ ���� ����.  

	long long item; //������ �Է� ���� 
	for (i = 1; i <= 1000000; i *= 2)
	{
		check[i] = 1;
	}

	cin >> n >> m >> k;
	tree.assign(4097160, 0);


	seg_index = pow(2, (long long)ceil(log2(n)));

	for (i = 0; i < n; i++)
	{
		cin >> item;
		tree[seg_index + i] = item;
	}
	//����� ���� �ϰ� 
	for (i = seg_index - 1; i > 0; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	//�ٲ�� �Է��� ���߿� �����鼭 �׶��׶����� ��� .
	for (i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			//�Լ��� ���� �ٲٴ°� 
			change(b, c);
		}
		else
		{
			//���ϴ� ��
			seg_sum(seg_index + b - 1, seg_index + c - 1);
		}
	}


	return 0;
}




void change(long long locate, long long value)
{
	long long index = seg_index + locate - 1;
	tree[index] = value;

	while (true)
	{
		if (index / 2 == 0) break;
		else
		{
			//���� �θ����� ���� Ʈ���� �θ� ������ ��*2 Ʈ���� �θ� ������ �� *2+1
			tree[index / 2] = tree[index / 2 * 2] + tree[index / 2 * 2 + 1];
			index /= 2;
		}
	}
}



void seg_sum(long long start, long long end)
{


	long long large = 0;
	long long small = 0;

	large = sub_sum(end);

	//���� ���� ���� ��Ʈ Ʈ����  start�� seg_index�� ���� ������
	if (start != seg_index)
	{
		small = sub_sum(start - 1);
	}


	cout << large - small << '\n';

}

long long sub_sum(long long index)
{
	long long sum = 0;
	long long copy_index = index;


	while (check[copy_index] != 1)
	{
		//Ȧ�� 
		if (copy_index % 2 == 1)
		{
			copy_index = copy_index / 2;
		}
		//¦��
		else
		{
			sum += tree[copy_index];
			//���������� �밢���� ��������(������ ����) �������� �밢���� �ϱ� ���ؼ� 
			copy_index = copy_index / 2 - 1;

		}
	}



	sum += tree[copy_index];
	return sum;
}