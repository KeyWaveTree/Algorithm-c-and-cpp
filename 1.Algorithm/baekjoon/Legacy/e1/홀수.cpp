#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[7] = { 0 };	
	int min=101;
	int sum = 0;
	bool flag = false;

	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];
		if (arr[i] % 2 != 0)
		{
			if (min > arr[i]) min = arr[i];
			sum += arr[i];
			flag = true;
		}
	}

	if (flag) 
	{
		cout << sum << '\n';
		cout << min<<'\n';
	}
	else
	{
		cout << " - 1";
	}

	return 0;
}