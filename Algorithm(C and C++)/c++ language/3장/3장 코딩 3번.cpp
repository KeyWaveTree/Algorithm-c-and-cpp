#include<iostream>
#include<math.h>

using namespace std;

double hypot(double b1, double b2)
{
	return sqrt(b1* b1 + b2 * b2);
}

int main()
{
	double a, b;
	cin >> a >> b;
	cout << (int)hypot(a, b);
}