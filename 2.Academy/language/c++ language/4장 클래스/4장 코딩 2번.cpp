#include<iostream>

using namespace std;

class Sum
{
	int n1;
	int n2;

public:
	void setOper(int *one,int * two)
	{
		this->n1 = *one;
		this->n2 = *two;
	}

	int add()
	{
		return (this->n1 + this->n2);
	}
};

int main()
{
	Sum s;
	int n, m;

	cin >> n >> m;
	s.setOper(&n, &m);
	cout << s.add();
}