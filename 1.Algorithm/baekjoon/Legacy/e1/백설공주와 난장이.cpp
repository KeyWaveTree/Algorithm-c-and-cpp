#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int arr[7];
	int temp;

	for (int i = 0; i < 7; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	cout << arr[6]<<'\n';
	cout << arr[5] << '\n';

	return 0;
}