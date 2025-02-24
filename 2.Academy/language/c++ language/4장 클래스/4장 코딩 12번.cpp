#include<iostream>

using namespace std;

class Time
{
	int h;
	int m;
	int s;

public:
	void setTime(int hour, int minute, int second)
	{
		this->h = hour;
		this->m = minute;
		this->s = second;
	}

	void print() const
	{
		printf("%02d : %02d : %02d", h, m, s);
	}
};

//void Time::print() const
//{
//
//}

int main()
{
	Time t;
	int h, m, s;
	cin >> h >> m >> s;

	t.setTime(h, m, s);
	t.print();
	return 0;
}