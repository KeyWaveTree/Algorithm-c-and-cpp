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
	//조상 바꾸기
	return u[my] = union_find(u[my]);
}

bool compare(const map& a, const map& b)
{
	return a.v < b.v;
}

int main()
{
	//크루스컬로 

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int i;
	int v, e; //노드, 엣지
	int start, end, w;//start, end, weght
	int cnt = 0; //노드 개수 확인

	cin >> v >> e;

	for (i = 1; i <= e; i++)
	{
		cin >> start >> end >> w;
		arr[i].s = start;
		arr[i].e = end;
		arr[i].v = w;
	}

	sort(arr + 1, arr + e + 1, compare);

	//선택 union find를 통해서 
	//초반 조상들 자신
	//사이클 확인
	for (i = 1; i <= v; i++)
	{
		u[i] = i;
	}

	//각각 노드의 조상
	int temp1;
	int temp2;

	//간선의 갯수 만큼
	for (i = 1; i <= e; i++)
	{
		//가족 연결
		temp1 = union_find(arr[i].s);//start
		temp2 = union_find(arr[i].e);//end

		//직계조상이 다른 경우에는 결혼을 할 수 있다.
		if (temp1 != temp2)
		{
			u[temp1] = temp2;
			//가중치 저장 혹은 인접행렬 저장
			value += arr[i].v;
			cnt++;


		}
		if (v - 1 == cnt) break;
	}

	cout << value;

	return 0;

}