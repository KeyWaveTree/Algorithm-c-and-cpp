#include<iostream>

using namespace std;

//check �迭 ���� ���� �ε����� ���� �ִٸ� ī��Ʈ �� �� 
int main()
{
	int check[1001] = { 0 };
	int cnt = 0;
	int n, p;
	int m;
	
	cin >> n >> p;
	m = n;
	check[m] = ++cnt;
	while (1)
	{
		m = (m * n) % p;
		cnt++;
		if (check[m] != 0)
		{
			//check[cnt]�� �̹� ����Ŭ�� ���鼭 ���� �� �׷��Ƿ� ���� cnt�� ���� ���� ��
			printf("%d", cnt - check[m]);
			break;
		}
		else check[m] = cnt;
	}
}
//map<int, int> check;
//int cnt = 0;
//
//int cycle_check(int op, int ori ,int mod)
//{
//	int c = (op * ori) % mod;
//	if (c == 0) return cnt;
//	else if (check.find(c)==check.end())
//	{
//		check.insert({ c, c });
//		cnt++;
//		cycle_check(c, ori, mod);
//	}
//	else
//	{
//		return cnt;
//	}
//}
// 
//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	printf("%d", cycle_check(n, n, m));
//}