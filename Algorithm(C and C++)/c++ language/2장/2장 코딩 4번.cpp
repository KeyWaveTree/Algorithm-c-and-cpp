#include<iostream>
using namespace std;

int main()
{
	int in;
	bool flag = 1;
	for (int i = 0; i < 5; i++)
	{
		cin >> in;
		if (in == 5) flag = 0;
	}
	if (flag) cout << "����� ��";
	else cout << "��ǻ�� ��";

	return 0;
}