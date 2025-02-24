#include<iostream>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, m, w;
	int sum = 0;//전체시간
	cin >> h >> m;
	cin >> w;
	
	//먼저 전체 시간에서 구하자 - 분단위
	sum = h * 60 + m + w;

	//시간
	h = sum / 60 % 24;
	
	//분
	m = (sum - (h * 60)) % 60;

	//만약 초까지 한다면
	/*
	h = sum / 3600 % 24;
	m = (sum - (h * 3600)) % 60;
	w= sum% 60;
	*/

	cout << h << " " << m<<" "<<w;

	return 0;
}