#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int t;
	int n, m;

	//�ּ� ���д� Ʈ���� ���丸 �˰� ������ Ǯ �� ����
	scanf("%d", &t); //�׽�Ʈ ���̽� ����
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