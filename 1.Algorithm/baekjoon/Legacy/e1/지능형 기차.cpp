#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int in, out;
	int max = 0;
	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		cin >> out;
		cin >> in;

		sum = sum - out + in;
		if (sum > max)max = sum;
	}
	
	cout << max;
	return 0;
}