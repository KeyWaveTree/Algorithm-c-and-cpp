#include<iostream>

using namespace std;

class Ractangle
{
public:
	int w, h;
	int ractArea()
	{
		return this->w * this->h;
	}
};

int main()
{
	Ractangle ract;
	ract.h = 100;
	ract.w = 100;
	cout << ract.ractArea();
}