#include<iostream> //cstdlib는 포함이 안되어 있는데 비주얼 스튜디오에서 포함시킴
#include<cstdlib>
#include<ctime>

using namespace std;

int main()
{
	srand(time(NULL));

	int r = rand() % 100 + 1;
	int ans = 0;
	int cnt = 0;

	do
	{
		cin >> ans;
		if (ans < r) cout << "값이 작다." << '\n';
		else if (ans > r) cout << "값이 크다." << '\n';
		else break;
		cnt++;
	} while (true);
	cout << cnt;
}