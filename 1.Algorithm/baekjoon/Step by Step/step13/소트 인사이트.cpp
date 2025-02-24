#include<iostream>
#include<string>
using namespace std;

int main()
{
	char temp = '\0';
	bool flag = true;
	string n;
	cin >> n;

	for (int i = 0; i < n.length(); i++)
	{
		for (int j = 0; j < n.length() - i - 1; j++)
		{
			if (n[j] < n[j + 1] )
			{
				flag = false;
				temp = n[j];
				n[j] = n[j + 1];
				n[j + 1] = temp;
			}
		}
		if (flag) break;
	}

	cout << n;

	return 0;
}