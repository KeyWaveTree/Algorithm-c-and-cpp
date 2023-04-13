#include<iostream>

using namespace std;

int arr[10000001];
int main()
{
	int n;
	int num;
	int i = 0;
	cin >> n;
	for (i ; i < n; i++)
	{
		cin >> num;
		arr[num]++;
	}

	for (i = 0; i <= 10000000; i++)
	{
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}