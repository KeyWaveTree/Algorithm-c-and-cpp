#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int p, n, won;

	cin >> p >> n >> won;

	printf("%d", (p * n) % won);
}