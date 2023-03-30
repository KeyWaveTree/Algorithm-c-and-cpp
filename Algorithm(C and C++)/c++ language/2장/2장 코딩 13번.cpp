#include<iostream>

using namespace std;

int main()
{
	int next = 1;
	int fibo = 0;
	int temp = 0;
	int n;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << fibo << " ";
		temp = fibo;
		fibo = next;
		next = temp + next;
	}
}