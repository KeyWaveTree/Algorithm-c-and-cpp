#include<iostream>
#include<math.h>
using namespace std;

double calc_volume(double r)
{
	return (4.0 / 3.0 * 3.14 * pow(r, 3));
}

int main()
{
	double r;
	cin >> r;

	cout << calc_volume(r);
}