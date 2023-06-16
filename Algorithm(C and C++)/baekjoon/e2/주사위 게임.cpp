#include<iostream>

using namespace std;

int get_prize(int d1, int d2, int d3)
{
	int prize = 0;
	if (d1 == d2 && d2 == d3)
	{
		prize = 10000 + (d1 * 1000);
	}
	else if (d1 == d2)
	{
		prize = 1000 + d1 * 100;
	}
	else if (d1 == d3)
	{
		prize = 1000 + d3 * 100;
	}
	else if (d3 == d2)
	{
		prize = 1000 + d2 * 100;
	}
	else
	{
		prize = ((d1 > d2 && d1 > d3) ? d1 : ((d2 > d3) ? d2 : d3)) * 100;
	}
	return prize;
}

int main()
{
	int d1, d2, d3;
	int max = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> d1 >> d2 >> d3;
		if (max < get_prize(d1, d2, d3)) 
		{
			max = get_prize(d1, d2, d3);
		}
	}

	printf("%d", max);

	return 0;
}
