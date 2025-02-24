#include<iostream>

using namespace std;

//피타고라스 정리 문제 

int main()
{
	int a, b, c;
	int max = 0;
	while (true)
	{
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		
		max = (a > b && a > c) ? a : ((b > c) ? b : c);

		if (max == a && (a*a) == (b*b) + (c*c))
		{
			cout << "right" << '\n';
		}
		else if (max == b && (b*b) == (a*a) + (c*c))
		{
			cout << "right" << '\n';
		}
		else if (max ==c && (c*c) == (a*a) + (b*b))
		{
			cout << "right"<< '\n';
		}
		else
		{
			cout << "wrong"<<'\n';
		}
	}
	return 0;
}