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
	check = boul[0];
	for (int i = 1; i < boul.length(); i++)
	{
		if (boul[i] == check) cnt += 5;
		else
		{
			cnt += 10;
			check = boul[i];
		}
	}

	cout << cnt;
	return 0;
}