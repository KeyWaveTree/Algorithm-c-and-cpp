#include<iostream>
#include<string>

using namespace std;

int main()
{
	int i = 666;
	int j, n;
	int cnt = 0;
	string sss;

	cin >> n;
	while (1)
	{
		sss = to_string(i);
		for (j = 0; j < sss.length()-2; j++)
		{
			if (sss[j] == '6' && sss[j + 1] == '6' && sss[j + 2] == '6')
			{
				cnt++;// ������ �� üũ ī��Ʈ
				if (n == cnt) break;
			}
		}
		if (n == cnt) break;
		i++;
	}
	cout << i;
}