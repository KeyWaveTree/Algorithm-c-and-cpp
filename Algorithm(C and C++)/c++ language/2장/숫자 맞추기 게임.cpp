#include<iostream> //cstdlib�� ������ �ȵǾ� �ִµ� ���־� ��Ʃ������� ���Խ�Ŵ
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int r = rand() % 100 + 1;
	int ans = 0;
	int cnt = 0;

	do
	{
		cin >> ans;
		if (ans < r) cout << "���� �۴�." << '\n';
		else if (ans > r) cout << "���� ũ��." << '\n';
		else break;
		cnt++;
	} while (true);
	cout << cnt;
}