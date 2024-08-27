	#include<iostream>

	using namespace std;

	int main()
	{
		int n;
		int a=0, b=1;
		int fibo = 1;

		cin >> n;

		for (int i = 2; i <= n; i++)
		{
			fibo = (a + b)%10007;
			a = b;
			b = fibo;
		}

		cout << fibo;
		return 0;
	}