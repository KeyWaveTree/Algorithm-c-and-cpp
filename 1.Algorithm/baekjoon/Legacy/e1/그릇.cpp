#include<iostream>
#include<string>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	char check = '\0';
	int cnt = 10;
	string boul;

	cin >> boul;
	
	for (int i = 1; i < boul.length(); i++)
	{
		if (boul[i - 1] == boul[i])cnt += 5;
		else cnt += 10;
	}
	cout << cnt;
	return 0;
}