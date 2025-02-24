#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int p, n, won;

	cin >> p >> n >> won;

    if ((p * n) - won >= 0)
    {
        printf("%d", (p * n) - won);
    }
    else
    {
        printf("0");
    }
}