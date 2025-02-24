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

long long seg_index;//처음 인덱스를 지정해준다. 

int main()
{
	freopen("input.txt", "r", stdin);
	cin.tie(), cout.tie(), ios::sync_with_stdio(false);

	long long i;
	long long n, m, k;
	long long a, b, c;
	//m 수의 변경이 일어난 횟수 
	//k 는 구간의 합을 구함.  

	long long item; //원소의 입력 변수 
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
	//계산을 먼저 하고 
	for (i = seg_index - 1; i > 0; i--)
	{
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}

	//바뀌는 입력은 나중에 받으면서 그때그때마다 계산 .
	for (i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			//함수를 만들어서 바꾸는것 
			change(b, c);
		}
		else
		{
			//더하는 것
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
			//현재 부모노드의 값은 트리의 부모 지정한 값*2 트리의 부모 지정한 값 *2+1
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

	//만약 지금 세그 먼트 트리의  start가 seg_index와 같지 않으면
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
		//홀수 
		if (copy_index % 2 == 1)
		{
			copy_index = copy_index / 2;
		}
		//짝수
		else
		{
			sum += tree[copy_index];
			//오른쪽으로 대각선을 하지말고(더하지 말고) 왼쪽으로 대각선을 하기 위해서 
			copy_index = copy_index / 2 - 1;

		}
	}



	sum += tree[copy_index];
	return sum;
}