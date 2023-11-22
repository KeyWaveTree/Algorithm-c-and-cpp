#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

typedef struct table
{
	int color;
	int size;
	int ans=0; //누적합 합 
};

map<int, table> first_come; //입력한 순서대로 출력하기 위해서
table arr[200001];
int check[200001];

bool compare(const table& a, const table& b)
{	
	return a.size < b.size;
}

int main()
{
	freopen("input.txt", "r", stdin);
	
	int n;
	int all_sum;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", arr[i].color, arr[i].size);
	}

	sort(arr + 1, arr + n + 1, compare);


}