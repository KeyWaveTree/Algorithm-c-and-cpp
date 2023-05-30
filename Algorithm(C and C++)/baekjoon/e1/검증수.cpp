#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int a, b, c, d, e;
	int sum;
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
	
	sum=(a* a) + (b * b) + (c * c) + (d * d) + (e * e);

	cout << sum%10;
	return 0;
}