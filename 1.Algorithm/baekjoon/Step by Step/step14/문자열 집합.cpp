#include<iostream>
#include<string>
#include<set>

using namespace std;

int main() 
{
	set<string> setString;
	string check;
	int n, m;
	int i;
	int cnt = 0;

	scanf("%d %d", &n, &m);
	for (i = 0; i < n + m; i++)
	{
		cin >> check;
		if (i <= n) setString.insert(check);
		if (i > n && setString.count(check)) cnt++;
	}
	printf("%d", cnt);

	return 0;
}