#include<iostream>

using namespace std;

int main()
{
	int h, m, s;
	int time;
	int t=0;
	//초단위 시간
	//h 3600초
	//m 60초
	//s 1초
	cin >> h >> m >> s;
	cin >> time;
	//모든 시간 초단위로 바꿔서 계산
	t = h * 3600 + m * 60 + s+time;
	//시간 지정 -24시간 이상 넘어가면 안됨
	h = t / 3600 % 24;
	//분 지정- 모든시간에서 시간을 없애야 함
	m = (t - h * 3600) / 60 %60;
	//초 지정 
	s= t % 60;

	printf("%d %d %d", h, m, s);

	return 0;
}