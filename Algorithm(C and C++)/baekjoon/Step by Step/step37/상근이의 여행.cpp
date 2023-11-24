#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int t;
	int n, m;

	//최소 스패닝 트리의 개념만 알고 있으면 풀 수 있음
	scanf("%d", &t); //테스트 케이스 개수
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m); //n - vertax, m - edge 
		
		for (int j = 0; j < m; j++)
		{
			int a, b;
			scanf("%d %d",&a, &b);
		}

		printf("%d\n", n - 1);
	}

	return 0;
}