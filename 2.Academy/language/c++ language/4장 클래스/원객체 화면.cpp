#include<iostream>
#include<Windows.h>

using namespace std;

class Circle
{
public:
	int x1, y1;
	int x2, y2;

};

int main()
{
	Circle c;
	c.x1 = c.y1 = 100, c.x2 = c.y2 = 180;
	HDC hdc = GetWindowDC(GetForegroundWindow());
	Ellipse(hdc, c.x1, c.y1, c.x2, c.y2);
}