#include<iostream>

using namespace std;

int fibonacci(int n, int m,int day)
{
	if (day == 1) return n;
	else return fibonacci(m, n + m, day - 1);
}

int main()
{
	int today;
	int toT;
	int i, j;
	cin >> today >> toT;


	for (i = 1; i < toT; i++)
	{
		for (j = 1; j < toT; j++)
		{
			if (fibonacci(i, j, today) == toT)
			{
				printf("%d\n%d", i, j);
				return 0;
			}
		}
	}
}