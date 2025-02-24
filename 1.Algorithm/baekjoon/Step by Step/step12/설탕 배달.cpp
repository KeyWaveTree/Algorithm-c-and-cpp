#include<iostream>

using namespace std;

int main()
{
	int n;
	int three;
	int sum = 0;
	bool flag = false;

	cin >> n;
	if (n % 5 == 0)
	{
		cout << n / 5;
	}

	else if (n % 5 != 0)
	{
		sum = n / 5;
		three = n % 5;
		flag = true;
	}
	else if (three % 3 == 0 && flag)
	{
		cout << sum + 1;
	}
	else
	{
		cout << -1;
	}
	return 0;
}