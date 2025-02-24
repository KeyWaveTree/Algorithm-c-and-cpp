#include<iostream>
#include<string>
using namespace std;

class Person
{
	string name;
	int age;

public:
	void setPerson(string *name, int *age)
	{
		this->name = *name;
		this->age = *age;
	}
	void print()
	{
		cout << "이름: " << this->name<<'\n';
		cout << "나이: " << this->age << "\n";
	}
};

int main()
{
	Person p;
	string name;
	int age;
	cin >> name >> age;
	p.setPerson(&name, &age);
	p.print();
}