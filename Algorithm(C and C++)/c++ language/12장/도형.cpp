#include<iostream>

using namespace std;

class Shape
{
protected:
	int x, y;

public :
	Shape() { this->x = this->y = 0; }
	Shape(int x, int y):x{x}, y{y}{}
	virtual void draw()
	{
		cout << "shape" << '\n';
	}
};

class Circle:public Shape
{
	int r;
public:
	Circle(int x, int y, int r)
	{
		Shape(x, y);
		this->r = r;
	}

	void draw()
	{
		cout << "circle" << '\n';
	}
};

class Rect:public Shape
{
	int h;
	int w;

public:
	Rect(int x1, int y1, int x2, int y2)
	{
		Shape(x1, y1);
		this->h = y2;
		this->w = x2;
	}
public:
	void draw()
	{
		cout << "rect" << '\n';
	}
};

int main()
{
	Shape* shapes[3];

	shapes[0] = new Rect(rand() % 600, rand() % 300, rand() % 100, rand() % 100);
	shapes[1] = new Circle(rand() % 600, rand() % 300, rand() % 100);
	shapes[2] = new Circle(rand() % 600, rand() % 300, rand() % 100);
	
	
	for (auto& i : shapes)
	{
		i->draw();
	}

	return 0;
}