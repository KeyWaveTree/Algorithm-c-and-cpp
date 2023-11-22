#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if (a == b && a== c) cout << 10000 + (a * 1000);
	else if (a == b || a == c) cout << 1000 + (a * 100);
	else if (c == b) cout << 1000 + (c * 100);
	else cout << max(max(a,b),c) * 100;

	return 0;
}