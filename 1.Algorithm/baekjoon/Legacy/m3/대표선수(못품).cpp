#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	int i, j;
	int power;

	//�Է�
	cin >> n >> m;

	vector<vector<int>> student(n, vector<int>(m, 0));
	//2���� �����Ҵ�
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			cin >> student[i][j];
		}

		//����
		sort(student[i].begin(), student[i].end(), [](const int& a, const int& b) { return a < b; });
	}

	

}