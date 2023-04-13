#include<iostream>

using namespace std;

class Box
{
	int length=NULL;
	int width= NULL;
	int height=NULL;

public:
	Box() 
	{
		length = width = height = 0;
	}

	Box(int len, int w, int h) :length{ len }, width{ w }, height{ h }{}

	int getLen() { return length; }
	int getW() { return width; }
	int getH() { return height; }

	void setLen(int len) { length = len; }
	void setW(int w) { width = w; }
	void setH(int h) { height = h; }

	bool empty()
	{
		if (length == NULL && width == NULL && height == NULL) return 1;
		else return 0;
	}

	int getVolume()
	{
		return length * width * height;
	}

	void print()
	{
		cout << "����" << length<<'\n';
		cout << "�ʺ�" << width << '\n';
		cout << "����" << height << '\n';
		cout << "����" << length*width*height << '\n';
	}
};

int main()
{
	Box a;
	Box b{3, 2, 4};

	a.print();
	b.print();

	return 0;
}